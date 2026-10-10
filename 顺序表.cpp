#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int listtype;
struct seqlist {
    listtype *data;
    int len;

};
seqlist* initList(){
    seqlist *L=new seqlist;
    L->data=new listtype[MAXSIZE];
    L->len=0;
    return L;
}
int addData(seqlist &l,listtype e ) {
    if(l.len>=MAXSIZE)
    {
        cout << "false";
        return 0;
    }
    l.data[l.len]=e;
    l.len++;
    return 1;
}
int insertElem(seqlist &l,int pos,listtype e) {
    if(pos<=l.len)
    {
        for(int i = l.len-1; i >= pos-1; i--) {
            l.data[i+1]=l.data[i];

        }
        l.data[pos-1]=e;
        l.len++;
    }
    return 1;

}
int deletElem(seqlist &l,int pos,listtype & e) {
    e=l.data[pos-1];
    if(pos<l.len) {
        for(int i = pos-1; i < l.len-1; i++) {
            l.data[i]=l.data[i+1];
        }
        l.len--;
        return 1;
    }
    return 0;
}
void listElem(seqlist & l) {
    for(int i = 0; i < l.len; i++) {
        cout << l.data[i];
    }
    cout << '\n';
}
int main(int argc, char** argv) {
    seqlist *l=initList();

    return 0;

}

// struct test
// {
//     int *data;
//     int len;
// };
// test* init(){
//     test* l=new test;
//     l->data=new int[MAXSIZE];
//     l->len=0;
//     return l;
// }