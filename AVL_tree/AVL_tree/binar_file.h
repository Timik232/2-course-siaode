#ifndef __BINAR_FILE_H__
#define __BINAR_FILE_H__
class binar_file
{
public:
	void create_bit(string name);
	void print_file(string name);
	bool text_to_binar(string textName, string name);
	bool binar_to_text(string textname, string name);
	business get_by_index(string name, int index);
	bool delete_by_key(string name, string key);
	bool insert_element(string name, business st);
	bool delete_by_index(string name, int index);
};
#endif
