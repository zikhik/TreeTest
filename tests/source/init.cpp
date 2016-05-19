#include <tree.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream> 
using namespace std;
                  
SCENARIO("Add_int", "[add]"){
  BStree<int> BStree;
  REQUIRE(BStree.Insert(7));
  REQUIRE(BStree.Insert(3));
  REQUIRE(BStree.Insert(5));
  REQUIRE(BStree.Search(3));
  REQUIRE(BStree.Search(5));
  REQUIRE(BStree.Search(7));
}

SCENARIO("Add_char", "[add_c]"){
  BStree<char> BStree;
  REQUIRE(BStree.Insert(5));
  REQUIRE(BStree.Insert(4));
  REQUIRE(BStree.Insert(6));
  REQUIRE(BStree.Search(4));
  REQUIRE(BStree.Search(5));
  REQUIRE(BStree.Search(6));
}

SCENARIO("Add_double", "[add_d]"){
  BStree<double> BStree;
  REQUIRE(BStree.Insert(7.62));
  REQUIRE(BStree.Insert(3.14));
  REQUIRE(BStree.Insert(5.85));
  REQUIRE(BStree.Search(3.14));
  REQUIRE(BStree.Search(5.85));
  REQUIRE(BStree.Search(7.62));
}

SCENARIO("Search_int", "[search_i]") {
BStree<int> BStree;
BStree.Insert(7);
BStree.Insert(5);
BStree.Insert(1);
BStree.Insert(9);
BStree.Insert(3);
REQUIRE(BStree.Search(7));
REQUIRE(BStree.Search(9));
REQUIRE(BStree.Search(5));
REQUIRE(BStree.Search(1));
REQUIRE(BStree.Search(3));
REQUIRE(!BStree.Search(0));
REQUIRE(!BStree.Search(8));
REQUIRE(!BStree.Search(6));
REQUIRE(!BStree.Search(4));
REQUIRE(!BStree.Search(2));
}

SCENARIO("Search_char", "[search_c]") {
  BStree<char> BStree;
BStree.Insert(7);
BStree.Insert(5);
BStree.Insert(1);
BStree.Insert(9);
BStree.Insert(3);
REQUIRE(BStree.Search(7));
REQUIRE(BStree.Search(9));
REQUIRE(BStree.Search(5));
REQUIRE(BStree.Search(1));
REQUIRE(BStree.Search(3));
REQUIRE(!BStree.Search(0));
REQUIRE(!BStree.Search(8));
REQUIRE(!BStree.Search(6));
REQUIRE(!BStree.Search(4));
REQUIRE(!BStree.Search(2));
}

SCENARIO("Search_double", "[search_d]") {
BStree<double> BStree;
BStree.Insert(7.77);
BStree.Insert(5.85);
BStree.Insert(1.29);
BStree.Insert(9.999);
BStree.Insert(3.14);
REQUIRE(BStree.Search(7.77));
REQUIRE(BStree.Search(9.999));
REQUIRE(BStree.Search(5.85));
REQUIRE(BStree.Search(1.29));
REQUIRE(BStree.Search(3.14));
REQUIRE(!BStree.Search(0.5));
REQUIRE(!BStree.Search(8.800));
REQUIRE(!BStree.Search(6.666));
REQUIRE(!BStree.Search(4.13));
REQUIRE(!BStree.Search(2.34));
}

SCENARIO("Read_int","[read_i]"){
BStree<int> BStree; ifstream fin("read.txt");
fin>>BStree;
fin.close();
REQUIRE(BStree.Search(7));
REQUIRE(BStree.Search(9));
REQUIRE(BStree.Search(5));
REQUIRE(BStree.Search(1));
REQUIRE(BStree.Search(3));
}

SCENARIO("Read_double","[read_d]"){
BStree<double> BStree; ifstream fin("read_db.txt");
fin>>BStree;
fin.close();
REQUIRE(BStree.Search(12.74));
REQUIRE(BStree.Search(15.62));
REQUIRE(BStree.Search(7.62));
REQUIRE(BStree.Search(3.14));
REQUIRE(BStree.Search(8.34));
REQUIRE(BStree.Search(25.15));
REQUIRE(BStree.Search(17.16));
}

SCENARIO("Print_file_int","[print_file_i]"){
BStree<int> BStree, tree_2; ofstream fout("print.txt", ios::app);
  BStree.Insert(7);
  BStree.Insert(3);
  BStree.Insert(5);
  fout<<BStree; fout<<-1;
  fout.close();
  ifstream fin("print.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.Search(7));
  REQUIRE(tree_2.Search(3));
  REQUIRE(tree_2.Search(5));
}

SCENARIO("Print_file_double","[print_file_d]"){
BStree<double> BStree, tree_2; ofstream fout("print_db.txt", ios::app);
  BStree.Insert(7.77);
  BStree.Insert(3.33);
  BStree.Insert(5.55);
  fout<<BStree; fout<<-1;
  fout.close();
  ifstream fin("print_db.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.Search(7.77));
  REQUIRE(tree_2.Search(3.33));
  REQUIRE(tree_2.Search(5.55));
}


SCENARIO("Print_console_int", "[print_console_i]"){
BStree<int> BStree;  
  BStree.Insert(7);
  BStree.Insert(3);
  BStree.Insert(5);
  REQUIRE(cout<<BStree);
}

SCENARIO("Print_console_char", "[print_console_c]"){
BStree<char> BStree;  
  BStree.Insert(7);
  BStree.Insert(3);
  BStree.Insert(5);
  REQUIRE(cout<<BStree);
}

SCENARIO("Print_console_double", "[print_console_d]"){
BStree<double> BStree;  
  BStree.Insert(7);
  BStree.Insert(3);
  BStree.Insert(5);
  REQUIRE(cout<<BStree);
}

SCENARIO("Iscl_add", "[I_a]"){
BStree<int> BStree; int O=0; 
BStree.Insert(1);
try{BStree.Insert(1);}
catch(Exist &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_not_open", "[I_no]"){
BStree<int> BStree; int O=0; ifstream fin("errotypeoffile");
try{fin>>BStree;}
catch(File_Not_Open &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust1", "[I_p1]"){
BStree<int> BStree; int O=0; 
try{cout<<BStree;}
catch(Empty &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust2", "[I_p2]"){
BStree<int> BStree; int O=0; ofstream fout("print_db.txt", ios::app);
try{fout<<BStree;}
catch(Empty &e){O++;}
fout.close();
REQUIRE(O==1);
}


SCENARIO("Del", "[del]"){
BStree<int> BStree; int O=0;
BStree.Insert(1);
BStree.Insert(4);
BStree.Insert(10);
BStree.Insert(3);
BStree.Insert(5);
BStree.Insert(8);
BStree.Insert(11);
//Удаляем корнень
REQUIRE(BStree.del(1));
REQUIRE(!BStree.Search(1));
REQUIRE(BStree.Search(4));
REQUIRE(BStree.Search(10));
REQUIRE(BStree.Search(3));
REQUIRE(BStree.Search(5));
REQUIRE(BStree.Search(8));
REQUIRE(BStree.Search(11));
//Удаляем элемент с 2мя поддеревьями
REQUIRE(BStree.del(4));
REQUIRE(!BStree.Search(1));
REQUIRE(!BStree.Search(4));
REQUIRE(BStree.Search(10));
REQUIRE(BStree.Search(3));
REQUIRE(BStree.Search(5));
REQUIRE(BStree.Search(8));
REQUIRE(BStree.Search(11));
//Удаляем элемент с 1 поддеревом
REQUIRE(BStree.del(5));
REQUIRE(!BStree.Search(1));
REQUIRE(!BStree.Search(4));
REQUIRE(BStree.Search(10));
REQUIRE(BStree.Search(3));
REQUIRE(!BStree.Search(5));
REQUIRE(BStree.Search(8));
REQUIRE(BStree.Search(11));
//Удаляем лист
REQUIRE(BStree.del(3));
REQUIRE(!BStree.Search(1));
REQUIRE(!BStree.Search(4));
REQUIRE(BStree.Search(10));
REQUIRE(!BStree.Search(3));
REQUIRE(!BStree.Search(5));
REQUIRE(BStree.Search(8));
REQUIRE(BStree.Search(11));
//Удаляем элемент с 1 поддеревом
REQUIRE(BStree.del(10));
REQUIRE(!BStree.Search(1));
REQUIRE(!BStree.Search(4));
REQUIRE(!BStree.Search(10));
REQUIRE(!BStree.Search(3));
REQUIRE(!BStree.Search(5));
REQUIRE(BStree.Search(8));
REQUIRE(BStree.Search(11));
//Удаляем лист
REQUIRE(BStree.del(11));
REQUIRE(!BStree.Search(1));
REQUIRE(!BStree.Search(4));
REQUIRE(!BStree.Search(10));
REQUIRE(!BStree.Search(3));
REQUIRE(!BStree.Search(5));
REQUIRE(BStree.Search(8));
REQUIRE(!BStree.Search(11));
}

SCENARIO("Add_int999", "[add_l]"){
  BStree<int> BStree{1,2,3};
  REQUIRE(BStree.Search(1));
  REQUIRE(BStree.Search(2));
  REQUIRE(BStree.Search(3));
}


SCENARIO("BST init with initializer list", "[init]") {
	BStree<int> BStree {8};
	REQUIRE( BStree.size() == 1 );
}

SCENARIO("BST search inserted element", "[search]") {
	BStree<int> BStree  {8, 4, 3};
	REQUIRE( BStree.Search(4) );
}

SCENARIO("BST search non inserted element", "[search]") {
	BStree<int> BStree  {8, 4, 3};
	REQUIRE( !BStree.Search(5) );
}

SCENARIO("BST delete non inserted element", "[delete]") {
	BStree<int> BStree {8};
	REQUIRE( !BStree.del(4) );

}

// 				  +----+
// 				  |-08-|									           *
// 				  +----+
//
//
// 						 				    08
// 						 				   ---->
SCENARIO("BST delete root without children", "[delete]") {
	BStree<int> BStree  {8};
	REQUIRE( BStree.del(8) );
}

//                +----+                                              +----+
//                |-08-|                                              | 04 |
//                +----+                                              +----+
//                  /                                                   /
//                 /                                                   /
//           +----+                                              +----+
//           | 04 |                                              | 03 |
//           +----+                                              +----+
//             /
//            /
//      +----+                              08
//      | 03 |                             ---->
//      +----+
SCENARIO("BST delete root with one child", "[delete]") {
	BStree<int> BStree  {8, 4, 3};
	REQUIRE( BStree.del(8) );
	REQUIRE( BStree == BStree<int>({4, 3}) );
}

//                +----+                                              +----+
//                |-08-|                                              | 09 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /          \
//            /         /  \                                      /            \
//      +----+    +----+    +----+          08              +----+              +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |              | 13 |
//      +----+    +----+    +----+                          +----+              +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete root with children", "[delete]") {
	BStree<int> BStree {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( BStree.del(8) );
	REQUIRE( BStree == BStree<int>({9, 4, 3, 10, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                                  /\
//            /         /  \                                                /  \
//      +----+    +----+    +----+          03                        +----+    +----+
//      |-03-|    | 09 |    | 13 |         ---->                      | 09 |    | 13 |
//      +----+    +----+    +----+                                    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete non root without children", "[delete]") {
	BStree<int> BStree  {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( BStree.del(3) );
	REQUIRE( BStree == BStree<int>({8, 4, 10, 9, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          11              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     |-11-|                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with one child", "[delete]") {
	BStree<int> BStree  {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( BStree.del(11) );
	REQUIRE( BStree == BStree<int>({8, 4, 3, 10, 9, 13, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    |-10-|                                    | 04 |    | 11 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          10              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with children", "[delete]") {
	BStree<int> BStree = {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( BStree.del(10) );
	REQUIRE( BStree == BStree<int>({8, 4, 3, 11, 9, 13, 12}) );
}
