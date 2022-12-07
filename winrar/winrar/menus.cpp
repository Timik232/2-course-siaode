#include <iostream>
#include <string>
#include <time.h>
#include <list>
#include <vector>
using namespace std;
#define _rand(min, max) ( rand() % ((max) - (min) + 1) + (min) )

struct dict
{
	char value;
	int amount;
	vector <bool> code;
	dict(char v, int am = 1)
	{
		this->value = v;
		this->amount = am;		
	}
};

string RLE(string line)
{
	string newline = "";
	int count = 1;
	char curr = line[0];
	bool is_end = false;
	int len = line.length();
	for (int i = 1; i < len; i++)
	{
		if (line[i] == curr) 
		{
			count++;
			if (i == len - 1)
			{
				newline += to_string(count) + curr;
			}
		}
		else
		{
			newline += to_string(count) + curr;
			curr = line[i];
			count = 1;
			if (i == len - 1)
			{
				newline += to_string(count) + curr;
			}
		}
	}
	return newline;
}
double ratio(int line, int newline)
{
	double res = line;
	return res / newline;
}

void RLE_menu()
{
	cout << "Choose action:\n1.Enter line to compress\n2.Long serie with similar symbols\n3.Long serie with different symbols\n4.Exit\n";
	string c;
	while (true)
	{
		cin >> c;
		if (c == "1")
		{
			string line;
			cout << "Enter line\n";
			cin >> line;
			string newline = RLE(line);
			cout << "Compressed line = " << newline << endl;
			cout << "Compression ratio is " << ratio(line.length(), newline.length()) << endl;
		}
		else if (c == "2")
		{
			string longline = "";
			for (int i = 0; i < 50; i++)
			{
				longline += "C";
			}
			for (int i = 0; i < 100; i++)
			{
				longline += "o";
			}
			for (int i = 0; i < 50; i++)
			{
				longline += "p";
			}
			for (int i = 0; i < 50; i++)
			{
				longline += "y";
			}
			cout << "Original line: " << longline << endl;
			string newline = RLE(longline);
			cout << "Compressed line = " << newline << endl;
			cout << "Compression ratio is " << ratio(longline.length(), newline.length()) << endl;
		}
		else if (c == "3")
		{
			srand(time(NULL));
			string randline = "";
			for (int i = 0; i < 200; i++)
			{
				int choose = rand() % 3;
				if (choose == 1)
				{
					char c = _rand(65, 90);
					randline += c;
				}
				else
				{
					char c = _rand(97, 122);
					randline += c;
				}
			}
			cout << "Original line: " << randline << endl;
			string newline = RLE(randline);
			cout << "Compressed line = " << newline << endl;
			cout << "Compression ratio is " << ratio(randline.length(), newline.length()) << endl;
		}
		else if (c == "4")
		{
			return;
		}
		else
		{
			cout << "Invalid input\n";
		}
	}
}
string LZ77(string line)
{
	const int BUF_SIZE = 4;
	string newline = "";
	int posbuf = 0;
	int last = 0;
	string buf;
	int offset, len;
	bool is_search = false;
	//newline = "<0,0,";
	newline = "00";
	newline.push_back(line[0]);
	//newline.push_back('>');
	buf = line[posbuf];
	int i = 1;
	do
	{
		
		if (buf.find(line[i]) != -1)
		{
			is_search = true;
			bool is_rec = false;
			offset = i - buf.rfind(line[i]) - posbuf;
			last = i;
			int count = i;
			len = 0;
			while (is_search)
			{
				if (buf.rfind(line.substr(last, count - last + 1)) == -1)
				{
					
					if (line[count] != buf[0] || count - last + 1 >= BUF_SIZE && line[count] == buf[0])
					{
						len += count - last;
						//newline += "<" + to_string(offset) + "," + to_string(len) + "," + line[count] + ">";
						newline += to_string(offset) + to_string(len) + line[count];
						is_search = false;
						i = count;
					}
					else
					{
						len += count - last + 1;
						last = count+1;
						is_rec = true;
					}
				}
				else
				{
					if (!is_rec && buf.rfind(line.substr(last, count - last + 1)) + posbuf != last - offset)
					{
						offset = last - buf.rfind(line.substr(last, count - last + 1)) - posbuf;
					}
					else if (is_rec && buf.rfind(line.substr(last, count - last + 1)) + posbuf != last - offset)
					{
						len += count - last;
						//newline += "<" + to_string(offset) + "," + to_string(len) + "," + line[count] + ">";
						newline += to_string(offset) + to_string(len) + line[count];
						is_search = false;
						i = count;
					}
				}
				count++;
				if (count >= line.length())
				{
					len += count - last;					
					//newline += "<" + to_string(offset) + "," + to_string(len) + "," + line[count] + ">";
					if (line[count] == ' ')
						newline += to_string(offset) + to_string(len);
					else 
						newline += to_string(offset) + to_string(len) + line[count];				
					is_search = false;
					i = count;
				}
			}
		}
		else
		{
			newline = "<0,0," + line[i] + '>';
		}
		i++;
		if (i > line.length())
		{
			break;
		}
		while (i - posbuf > BUF_SIZE)
		{
			posbuf++;
		}
		if (buf.find(line.substr(i - last, last)) == -1 && !is_search)
		{
			buf = line.substr(posbuf, i - posbuf);
		}
	} while (i < line.length());
	return newline;
}
string* push(string* arr, string el,int &size)
{
	string* newarr = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[size] = el;
	size++;
	return newarr;
}
int ind_find(vector <string> arr, string el)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == el)
			return i;
	}
	return -1;
}
string LZ78(string line)
{
	vector <string> dict;
	int size = 1;
	string newline = "";
	string buf = "";	
	newline.push_back('0');
	newline.push_back(line[0]);
	buf += line[0];
	dict.push_back(buf);
	int i = 1;
	do
	{
		buf = line[i];
		if (find(dict.begin(),dict.end(),buf) == dict.end())
		{
			dict.push_back(buf);
			//cout << buf[buf.length() - 1] << endl;
			newline.push_back('0');
			newline += buf[buf.length()-1];
		}
		else
		{
			int count = i;
			bool is_find = false;
			while (!is_find)
			{
				count++;
				buf += line[count];
				if (find(dict.begin(), dict.end(), buf) == dict.end())
				{
					dict.push_back(buf);
					newline += to_string(ind_find(dict, buf.substr(0, buf.length() - 1))+1) + buf[buf.length() - 1];
					is_find = true;
				}
				i = count;
			}
		}
		i++;
	} while (i < line.length());
	return newline;
}
void lempel_menu() //task 12
{

	cout << "Choose action:\n1.LZ77 test\n2.LZ78 test\n3.Exit\n";
	string c;
	while (true)
	{
		cin >> c;
		if (c == "1")
		{			
			string line = "0001001010101001101";
			cout << "Original line: " << line << endl;
			//line = "0001010010101001101";
			string newline = LZ77(line);
			cout << "Compressed line = " << newline << endl;
			cout << "Compression ratio is " << ratio(line.length(), newline.length()) << endl;
		}
		else if (c == "2")
		{
			string line = "commercommecommerce";
			cout << "Original line: " << line << endl;
			string newline = LZ78(line);
			cout << "Compressed line = " << newline << endl;
			cout << "Compression ratio is " << ratio(line.length(), newline.length()) << endl;
		}
		else if (c == "3")
		{
			return;
		}
		else
		{
			cout << "Invalid input, try again\n";
		}
	}
}
int dict_find(vector <dict> d, char v)
{
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i].value == v)
			return i;
	}
	return -1;
}
void increase(vector <dict> &d, char v)
{
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i].value == v)
			d[i].amount++;
	}
}
void sort(vector <dict>& d)
{
	for (int i = 0; i < d.size(); i++) {
		for (int j = 0; j < d.size()-1; j++) {
			if (d[j].amount < d[j+1].amount) {
				dict b = d[j]; 
				d[j] = d[j + 1]; 
				d[j + 1] = b; 
			}
		}
	}
}

int get_middle(vector <dict> d, int start, int end)
{
	int middle = (start + end) / 2;
	int res1 = 0;
	int res2 = 0;
	for (int i = start; i < middle; i++)
	{
		res1 += d[i].amount;
	}
	for (int i = middle; i < end; i++)
	{
		res2 += d[i].amount;
	}
	while (true)
	{
		if (res1 > res2)
		{
			if (res1 - d[middle - 1].amount <= res2 + d[middle - 1].amount)
			{
				return middle;
			}
			else
			{
				res1 -= d[middle - 1].amount;
				res2 += d[middle - 1].amount;
				middle--;
			}
		}
		else if (res1 == res2)
		{
			return middle;
		}
		else
		{
			if (res1 + d[middle].amount >= res2 - d[middle].amount)
			{
				return middle;
			}
			else
			{
				res1 += d[middle].amount;
				res2 -= d[middle].amount;
				middle++;
			}
		}
	}
}

void get_tree(vector <dict> d, int start, int end, vector <string>& arr, string code)
{
	if (end - start == 1)
	{
		arr[start] = code;
		return;
	}
	int middle = get_middle(d, start, end);
	get_tree(d, middle, end, arr, code + "1");

	get_tree(d, start, middle, arr, code + "0");
}
void make_struct(vector <dict>& diction, string line)
{
	for (int i = 0; i < line.length(); i++)
	{
		if (dict_find(diction, line[i]) == -1)
		{
			dict d = dict(line[i]);
			diction.push_back(d);
		}
		else
		{
			increase(diction, line[i]);
		}
	}
}
void shenano()
{
	string line = "Цветом мой зайчишка – белый, А ещё, он очень смелый! Не боится он лисицы, Льва он тоже не боится.";
	//line = "aaaaaaaaaaaaaabbbbbbbcccccdddddeeee";
	vector <dict> diction;

	make_struct(diction, line);
	sort(diction);
	int middle = get_middle(diction,0,diction.size());
	vector <string> arr;
	arr.resize(diction.size());
	get_tree(diction,middle, diction.size(),arr,"1");

	get_tree(diction, 0, middle, arr,"0");
	/*for (int i = 0; i < arr.size(); i++)
	{
		cout << diction[i].value << " " << diction[i].amount << " " << arr[i] << endl;
	}*/
	for (int i = 0; i < diction.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == '0')
				diction[i].code.push_back(false);
			else 
				diction[i].code.push_back(true);
		}
		
	}
	string newline = "";
	for (int i = 0; i < line.length(); i++)
	{
		newline += arr[dict_find(diction, line[i])];
	}
	cout << newline;
}
struct haff 
{
	char value;
	int amount;
	haff* left;
	haff* right;
	haff()
	{
		left = nullptr;
		right = nullptr;
	};
	haff(char v, int a, haff* l = nullptr, haff* r = nullptr)
	{
		this->value = v;
		this->amount = a;
		this->left = l;
		this->right = r;
	}
};
bool compare(haff* h1, haff* h2)
{
	return h1->amount > h2->amount;
}
struct haffcode
{
	char value;
	string code;
	haffcode(char v, string c)
	{
		value = v;
		code = c;
	}
};
void haff_encode(vector <haffcode> dict, string code, haff* root)
{
	if (!root)
		return;
	if (!root->left && !root->right)
	{
		haffcode hcode = haffcode(root->value, code);
	}
	haff_encode(dict, code + "0", root->left);
	haff_encode(dict, code + "1", root->right);
}
string haff_decode(haff* root, int &index, string code)
{
	if (!root)
		return;
	if (!root->left && !root->right)
	{
		return to_string(root->value);
	}
	index++;
	if (code[index] == '0')
		haff_decode(root->left, index, code);
	else
		haff_decode(root->right, index, code);
}
void hoffman()
{
	string line = "Комолов Тимур Витальевич";
	vector <dict> diction;
	make_struct(diction, line);
	sort(diction);

}
