#include <iostream> 
#include <fstream> 
#include <list> 
using namespace std;

template <class T>
class BStree;
template <class T>
ostream & operator<< (std::ostream & out, BStree<T> &tree);

template <class T>
ofstream & operator<< (std::ofstream & fout, BStree<T> &tree);

template <class T>
ifstream & operator >> (std::ifstream & fin, BStree<T> &tree);

template <class T>
istream & operator >> (std::istream & in, BStree<T> &tree);

class Exceptions {
	char* err;
public:
	Exceptions(char* _err);
	char* what();
};
class File_Not_Open : public Exceptions {
public:
	File_Not_Open();
};
class Empty : public Exceptions {
public:
	Empty();
};
class Exist : public Exceptions {
public:
	Exist();
};
class Deleted : public Exceptions {
public:
	Deleted();
};
class Error_stream : public Exceptions {
public:
	Error_stream();
};

Exceptions::Exceptions(char* _err) : err(_err) {}
char* Exceptions::what() { return err; }
Exist::Exist() : Exceptions("ERROR: It's already exist!") {}
File_Not_Open::File_Not_Open() : Exceptions("ERROR: file is not open!") {}
Empty::Empty() : Exceptions("ERROR: The Binary BStree is empty!") {}
Deleted::Deleted() : Exceptions("ERROR: It was deleted before") {}
Error_stream::Error_stream() : Exceptions("ERROR: Stream error") {}
template <class T>
class BStree {
public:
	class NodeIterator;
	using iterator = NodeIterator;

	BStree() :root(nullptr) {};
	BStree(const initializer_list<T> & ilist);
	~BStree();
	bool operator == (const BStree<T> & tree);
	auto begin() const->iterator;
	auto end() const->iterator;
	bool Insert(const T x);// Äîáàâëåíèå ýëåìåíòà 
	bool Search(const T x);// Ïîèñê ýëåìåíòà 
	bool del(T x); //óäàëåíèå óçëà äåðåâà 
	size_t size();
	friend ostream & operator<< <>(ostream &out, BStree<T> &tree);
	friend ofstream & operator<< <>(ofstream &fout, BStree<T> &tree);
	friend ifstream & operator>> <>(ifstream &fin, BStree<T> &tree);
	friend istream & operator >> <>(istream & in, BStree<T> &tree);
	class Root;
	Root* root; //êîðåíü äåðåâà 

	static auto  fillListOfNodes(list<const Root*> & listOfNodes, const Root* root)->void;
	class NodeIterator {
	public:
		NodeIterator() = default;
		NodeIterator(const Root* root);
		auto operator == (const NodeIterator & _iterator) -> bool;
		auto operator != (const NodeIterator & _iterator) -> bool;
		auto operator ++()->NodeIterator;
		auto operator *() const -> const T &;
		list<const Root*> history_;

	};
};
template <class T>
class BStree<T>::Root {
public:
	Root(T x);
	void destroy(Root* root);
	void Insert(const T x);
	bool Search(const T x);
	size_t size_;
	size_t sizeRoot();
	bool show();
	bool print_file(ofstream &fout);
	void del(T el);
	const T find_min(const Root* el);
	const T get_data() { return data; };
	T data;
	Root *left;
	Root *right;
private:

};
