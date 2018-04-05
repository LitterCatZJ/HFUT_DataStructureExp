#include "Forest.h"
#include <fstream>


Forest::Forest()
{
    //ctor
}

Forest::Forest(string path)
{
    //˫�׽ڵ�Ͷ�������ֱ��ʼ��
    ifstream fin(path);
    string nodes;
    char tc;
    fin.get(tc);
    while(tc!='\n')
    {
        if(tc!=' ') {
            pnode tp;
            tp.data=tc;
            tp.parent=-1;
            ptree.push_back(tp);
        }
        fin.get(tc);
    }
    //��ÿ��Ԫ�ذ��Һø��ڵ�
    char fat,child;
    int idx=-1,cidx;
    while(!fin.eof())
    {
        fin>>fat>>child;
        for(int i=0;i<ptree.size();i++)
        {
            if(ptree[i].data==fat) idx=i;
            if(ptree[i].data==child) cidx=i;
        }

        ptree[cidx].parent=idx;
    }
    //�����Ѿ���˫�ױ�ʾ�������ɹ������洴��һ�����������ʾ��ɭ��
    int v1;
    for(int i=0;i<ptree.size();i++)
        if(ptree[i].parent==-1)
        { v1=i; break; }

    create(root,v1);
    //��������ɭ�֣������ɭ�֣���ô�����ĸ���㿴���ֵܽڵ�

}


void Forest::create(csNode *&T,int v)
{
	int w;
	T=new csNode;
	T->data=ptree[v].data;
	T->firstChild=NULL;
	T->nextSibling=NULL;
	w=firstChild(v);  //����v�ĵ�һ�����ӽ��
	if(w!=-1)
	{
		create(T->firstChild,w);
	}

	w=next(v);       //����v����һ���ֵܽ��
	if(w!=-1)
	{
		create(T->nextSibling,w);
	}
}
int Forest::firstChild(int t)
{
    for(int i=0;i<ptree.size();i++)
    {
        if(ptree[i].parent==t) return i;
    }
    return -1;
}

int Forest::next(int t)
{
    for(int i=t+1;i<ptree.size();i++)
    {
        if(ptree[i].parent==ptree[t].parent) return i;
    }
    return -1;
}

void Forest::pre_order(csNode * pt)
{
    cout<<pt->data<<' ';
    if(pt->firstChild)    pre_order(pt->firstChild);
    if(pt->nextSibling)    pre_order(pt->nextSibling);
}

void Forest::post_order(csNode *pt)
{
    if(pt->firstChild) post_order(pt->firstChild);
    if(pt->nextSibling) post_order(pt->nextSibling);
    cout<<pt->data<<' ';
}

void Forest::level_print()
{
    queue<csNode *> q;
    q.push(root);q.push(0);
    csNode *tp;
    while(!q.empty())
    {
        tp=q.front();
        q.pop();
        if(tp==nullptr) {
            cout<<endl;
            q.push(0);
            tp=q.front();
            q.pop();
        }


        if(tp) cout<<tp->data<<' ';
        if(tp&&tp->firstChild)    q.push(tp->firstChild);
        while(tp)
        {
            tp=tp->nextSibling;
            if(tp) cout<<tp->data<<' ';
            if(tp&&tp->firstChild)    q.push(tp->firstChild);
        }

    }
}

void Forest::pre_order_level(csNode* pt,int level)
{
    cout<<"("<<pt->data<<','<<level<<")"<<' ';
    if(pt->firstChild)    pre_order_level(pt->firstChild,level+1);
    if(pt->nextSibling)    pre_order_level(pt->nextSibling,level);
}
void Forest::gen_print(csNode *pt)
{
    cout<<pt->data;
    if(pt->firstChild) {
        cout<<'(';
        gen_print(pt->firstChild);
    }
    if(pt->nextSibling) gen_print(pt->nextSibling);
    else cout<<')';
}
void Forest::print(int fg)
{
    if(fg==5) {
        for(pnode tp: ptree)
            cout<<tp.data<<":"<<tp.parent<<' ';
        cout<<endl;
    }
    else if(fg==1){
        cout<<"pre: ";
        pre_order(root);
        cout<<endl;
    }
    else if(fg==2)
    {
        cout<<"post: ";
        post_order(root);
        cout<<endl;
    }
    else if(fg==3)
    {
        cout<<"level: "<<endl;
        level_print();
        cout<<endl;
    }
    else if(fg==4)
    {
        cout<<"pre_and_level: "<<endl;
        pre_order_level(root,1);
        cout<<endl;
    }
    else if(fg==6)
    {
        cout<<"generalize_table: ";
        gen_print(root);
        cout<<endl;
    }
}

//��˫�ױ�ʾ��vector����߶�
int Forest::height()
{
    int h=1,h1=1;
    for(int i=0;i<ptree.size();i++)
    {
        h1=1;
        int pa=ptree[i].parent;
        while(pa!=-1)
        {
            pa=ptree[pa].parent;
            h1++;
        }
        if(h1>h) h=h1;
    }
    return h;
}

int Forest::node_count()
{
    return ptree.size();
}
int Forest::leaves()
{
    //�����һ������Ϊ�գ���ô��Ҷ�ӽڵ�
    int ct=0;
    for(int i=0;i<ptree.size();i++)
    {
        int w=firstChild(i);
        if(w==-1) ct++;
    }
    return ct;
}

int Forest::degrees()
{
    int d=1,d1=1;
    for(int i=0;i<ptree.size();i++)
    {
        d1=0;
        int w=firstChild(i);
        while(w!=-1)
        {
            d1++;
            w=next(w);

        }
        if(d1>d) d=d1;
    }
    return d;
}

Forest::~Forest()
{
    //dtor
}
