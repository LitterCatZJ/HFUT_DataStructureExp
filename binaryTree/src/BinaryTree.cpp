#include "BinaryTree.h"
#include <sstream>

BinaryTree::BinaryTree()
{
    //ctor
    root=nullptr;
}

BinaryTree::BinaryTree(string filepath)
{

    ifstream fin(filepath);
    if(fin.fail()){
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        root=nullptr;
    }
    else{
        vector<nodeinfo> vt;
        nodeinfo temp;
        while(!fin.eof())
        {
            fin>>temp.dat>>temp.lef>>temp.rig;
            vt.push_back(temp);
        }
        fin.close();
        int t=0;
        creat_node(root,vt,t);
    }
}
void BinaryTree::creat_node(node *& pt,vector<nodeinfo> vt,int& i)
{
    pt=new node;
    pt->data=vt.at(i).dat;
    pt->left=pt->right=nullptr;
    nodeinfo tmp=vt.at(i);
    if(tmp.lef) creat_node(pt->left,vt,++i);
    if(tmp.rig) creat_node(pt->right,vt,++i);

}

BinaryTree::BinaryTree(const BinaryTree& tc)
{
    creat_node(root,tc.root);
}
void BinaryTree::creat_node(node*& pt,node * pc)
{
    pt=new node;
    pt->data=pc->data;
    pt->left=pt->right=nullptr;
    if(pc->left) creat_node(pt->left,pc->left);
    if(pc->right) creat_node(pt->right,pc->right);
}
//�������
void BinaryTree::preorder_show(node * t)
{
    cout<<t->data<<' ';
    if(t->left) preorder_show(t->left);
    if(t->right) preorder_show(t->right);
}

void BinaryTree::inorder_show(node *t)
{
    if(t->left) inorder_show(t->left);
    cout<<t->data<<' ';
    if(t->right) inorder_show(t->right);

}

void BinaryTree::postorder_show(node * t)
{
    if(t->left) postorder_show(t->left);
    if(t->right) postorder_show(t->right);
    cout<<t->data<<' ';
}

void BinaryTree::print(int flag)
{
    if(flag==1) {
        preorder_show(root);cout<<endl;
    }
    else if(flag==2) {
        inorder_show(root);
        cout<<endl;
    }
    else {
        postorder_show(root);
        cout<<endl;
    }
}
void BinaryTree::inorder_and_level(node * pt,int level)
{
    if(level==1) pt=root;
    if(pt)
    {
        inorder_and_level(pt->left,level+1);
        cout<<"data: "<<pt->data<<", level: "<<level<<endl;
        inorder_and_level(pt->right,level+1);
    }
}
int BinaryTree::cal_height(node * pt)
{
    if(pt==nullptr) return 0;
    else
        return 1+max(cal_height(pt->left),cal_height(pt->right));
}
int BinaryTree::height()
{
    return cal_height(root);
}

int BinaryTree::cal_nodes(node* pt)
{
    if(pt==nullptr) return 0;
    else
        return 1+cal_nodes(pt->left)+cal_nodes(pt->right);
}
int BinaryTree::count()
{
    return cal_nodes(root);
}
int BinaryTree::cal_leaves(node * pt)
{
    if(pt->left==nullptr&&pt->right==nullptr) return 1;
    else if(pt->left&&pt->right)
        return cal_leaves(pt->left)+cal_leaves(pt->right);
    else if(pt->left)
        return cal_leaves(pt->left);
    else if(pt->right) return cal_leaves(pt->right);
}

int BinaryTree::leaves()
{
    return cal_leaves(root);
}
int BinaryTree::cal_two_degree(node * pt)
{
    if(pt->left && pt->right)
        return 1+cal_two_degree(pt->left)+cal_two_degree(pt->right);
    else if(pt->left)
        return cal_two_degree(pt->left);
    else if(pt->right)
        return cal_two_degree(pt->right);
    else return 0;
}

int BinaryTree::two_degree_nodes()
{
    return cal_two_degree(root);
}

void BinaryTree::find_father(node*& res,Type c,node* pt)
{
    if(root->data==c) res=nullptr;
    else{
         if(pt==nullptr) pt=root;
    if((pt->left&&pt->left->data==c) || (pt->right&&pt->right->data==c))
        res=pt;
    else{
        if(pt->left) find_father(res,c,pt->left);
        if(pt->right) find_father(res,c,pt->right);
    }
    }

}

void BinaryTree::about_x(Type x)
{
    //���ڵ�
    node *fat;
    find_father(fat,x);
    if(fat==nullptr) {
        cout<<"�ýڵ��Ǹ��ڵ�;";
        fat=root;
    }
    else cout<<"�ýڵ�ĸ��ڵ��ֵΪ��"<<fat->data<<";";

    //�ֵܽڵ�
    if(fat&&fat->left&&fat->left->data==x){
        if(fat->right) cout<<"�ýڵ�����ֵܵ�ֵΪ��"<<fat->right->data<<";";
        else cout<<"�ýڵ�û�����ֵ�;";


        //���ӽڵ�
        if(fat->left->left) cout<<"���ӵ�ֵΪ��"<<fat->left->left->data<<";";
        else cout<<"û������;";

        if(fat->left->right) cout<<"�Һ��ӵ�ֵΪ��"<<fat->left->right->data<<";";
        else cout<<"û���Һ���;";

    }
    else{
        if(fat->left) cout<<"�ýڵ�����ֵܵ�ֵΪ��"<<fat->left->data<<";";
        else cout<<"�ýڵ�û�����ֵ�;";

          //���ӽڵ�
        if(fat->right->left) cout<<"���ӵ�ֵΪ��"<<fat->right->left->data<<";";
        else cout<<"û������;";

        if(fat->right->right) cout<<"�Һ��ӵ�ֵΪ��"<<fat->right->right->data<<";";
        else cout<<"û���Һ���;";
    }

}
int BinaryTree::find_level(Type x,int lev,node* pt)
{
    if(pt==nullptr) pt=root;
    if(pt->data==x) { return lev; }
    else{
        int t1=0,t2=0;
        if(pt->left) t1=find_level(x,lev+1,pt->left);
        if(pt->right) t2=find_level(x,lev+1,pt->right);
        return t1==0?t2:t1;
    }
}
void BinaryTree::change_right_left(node* t)
{
    if(t==nullptr) t=root;
    node *tmp=t->left;
    t->left=t->right;
    t->right=tmp;
    if(t->left) change_right_left(t->left);
    if(t->right) change_right_left(t->right);
}

void BinaryTree::clear(node*t)
{
    if(t)
    {
        clear(t->left);
        clear(t->right);
        delete t;
    }
}

void BinaryTree::leaves2root(bool longest,node* pt,string path)
{
    if(pt==nullptr) pt=root;
    if(!pt->left&&!pt->right) {
        if(longest){
            if(find_level(pt->data)==height())
                cout<<pt->data<<"��"<<path<<endl;
        }
        else
            cout<<pt->data<<"��"<<path<<endl;
    }
    else{
        stringstream sinout;
        sinout<<pt->data;
        string tmp;sinout>>tmp;
        path=tmp+path;
        if(pt->left) leaves2root(longest,pt->left,path);
        if(pt->right) leaves2root(longest,pt->right,path);
    }
}
void BinaryTree::print_by_level()
{
    queue<node*> Q;
    Q.push(root);
    Q.push(0);
    do {
        node* node = Q.front();
        Q.pop();
        if (node) {
            cout << node->data << " ";
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
        }
        else if (!Q.empty()) {
            Q.push(0);
            cout << endl;
        }
    } while(!Q.empty());
}

Type BinaryTree::near_common_ancestor(Type a,Type b)
{
    node* fat1,*fat2;
    find_father(fat1,a);
    find_father(fat2,b);
    while(fat1!=fat2)
    {
        if(fat1==nullptr || fat2==nullptr) {
            fat1=root;
            break;
        }
        find_father(fat1,fat1->data);
        find_father(fat2,fat2->data);
    }
    return fat1->data;
}
//�������������㷨��ʵ��
BinaryTree::BinaryTree(Type a[],int n,bool avl)
{
    root=nullptr;
    for(int i=0;i<n;i++)
        if(avl) insert_avl(root,a[i]);
        else    insert(root,a[i]);
}
void BinaryTree::insert(node*&pt,Type x)
{
    if(pt==nullptr) {
        pt=new node;
        pt->data=x;
        pt->left=pt->right=nullptr;
    }
    else if(pt->data>x) insert(pt->left,x);
    else insert(pt->right,x);
}
BinaryTree::node* BinaryTree::search_sort(node*pt,Type x,bool prt)
{
    if(pt==nullptr) {
        if(prt) cout<<": ����ʧ��"<<x<<endl;
        return nullptr;
    }
    if(pt->data==x) {
        if(prt) cout<<": ���ҳɹ�"<<x<<endl;
        return pt;
    }
    else{
        if(prt) cout<<pt->data<<' ';
        if(x>pt->data) search_sort(pt->right,x,prt);
        else search_sort(pt->left,x,prt);
    }
}

void BinaryTree::remove(Type x)
{
    node *sf,*s;
    node* p=search_sort(root,x,false);
    find_father(sf,x);
    if(p->left==nullptr&&p->right==nullptr)
    {   delete p;
        if(sf->left==p) sf->left==nullptr;
        else sf->right==nullptr;
    }
    else if(p->left==nullptr&&p->right)
    {
        if(sf->left==p) sf->left=p->right;
        else sf->right=p->right;
        delete p;
    }
    else if(p->left&&p->right==nullptr)
    {
        if(sf->left==p) sf->left=p->left;
        else sf->right=p->left;
        delete p;
    }
    else
    {
        sf=p;s=p->left;
        while(s->right)
        {
            sf=s;
            s=s->right;
        }
        p->data=s->data;
        if(sf==p) sf->left=s->left;
        else sf->right=s->left;
        delete s;
    }
}
void BinaryTree::search(Type x)
{
    search_sort(root,x);
}

//AVL���ķ���
int BinaryTree::height_avl(node * pnode)
{
    if (pnode != nullptr)
    {
        return pnode->height;
    }
    return 0;
}
BinaryTree::node* BinaryTree::leftRotation(node* proot)
{
    node* prchild = proot->right;
    proot->right = prchild->left;
    prchild->left = proot;

    proot->height = max(height_avl(proot->left),height_avl(proot->right))+1;     //���½ڵ�ĸ߶�ֵ
    prchild->height = max(height_avl(prchild->left), height_avl(prchild->right)) + 1; //���½ڵ�ĸ߶�ֵ
    return prchild;
}
BinaryTree::node* BinaryTree::rightRotation(node* proot)
{
    node* plchild = proot->left;
    proot->left = plchild->right;
    plchild->right = proot;

    proot->height = max(height_avl(proot->left),height_avl(proot->right))+1;     //���½ڵ�ĸ߶�ֵ
    plchild->height = max(height_avl(plchild->left), height_avl(plchild->right)) + 1; //���½ڵ�ĸ߶�ֵ

    return plchild;
}
BinaryTree::node* BinaryTree::rightLeftRotation(node* proot)
{
    proot->right=rightRotation(proot->right);
    return leftRotation(proot);
}
BinaryTree::node* BinaryTree::leftRightRotation(node* proot)
{
    proot->left=leftRotation(proot->left);
    return rightRotation(proot);
}
BinaryTree::node* BinaryTree::insert_avl(node*&pnode,Type key)
{
    if (pnode == nullptr)    //Ѱ�ҵ������λ��
    {
        pnode = new node;
        pnode->data=key;
        pnode->left=pnode->right=nullptr;
    }
    else if (key > pnode->data)    //����ֵ�ȵ�ǰ���ֵ�󣬲��뵽��ǰ������������
    {
        pnode->right = insert_avl(pnode->right, key);
        if (height_avl(pnode->right) - height_avl(pnode->left) == 2) //��������ʧ��
        {
            if (key > pnode->right->data) //���һ���������������ҽڵ㣬��������
                pnode=leftRotation(pnode);
            else if (key < pnode->right->data)  //���������������������ڵ�,��������������ת
                pnode=rightLeftRotation(pnode);
        }
    }
    else if (key < pnode->data) //����ֵ�ȵ�ǰ�ڵ�ֵС�����뵽��ǰ������������
    {
        pnode->left = insert_avl(pnode->left, key);
        if (height_avl(pnode->left) - height_avl(pnode->right) == 2) //������뵼��ʧ��
        {
            if (key < pnode->left->data)        //����������뵽�����������ӽڵ��ϣ���������
                pnode = rightRotation(pnode);
            else if (key>pnode->left->data)
                pnode = leftRightRotation(pnode);//����ģ����뵽���������Һ��ӽڵ��ϣ��������������ת
        }
    }
    pnode->height= max(height_avl(pnode->left), height_avl(pnode->right)) + 1;
    return pnode;
}

BinaryTree::node* BinaryTree::remove_avl(node*&pnode,Type key)
{
    if (pnode != nullptr)
    {
        if (key == pnode->data)            //�ҵ�ɾ���Ľڵ�
        {
            //��AVLҲ�Ƕ�����������ɾ���ڵ�Ҫά�������������������
            if (pnode->left != nullptr&&pnode->right != nullptr)        //�����Ҷ���Ϊ��
            {
                // ����������������,����������ѡ��ڵ�����滻
                if (height_avl(pnode->left) > height_avl(pnode->right))
                {
                    //ʹ�����������ڵ������汻ɾ�ڵ㣬��ɾ�������ڵ�
                    node* ppre = maximum(pnode->left);        //���������ڵ�
                    pnode->data = ppre->data;                                //�����ڵ��ֵ���ǵ�ǰ���
                    pnode->left = remove_avl(pnode->left, ppre->data);    //�ݹ��ɾ�����ڵ�
                }
                else  //����������ѡ��ڵ�����滻
                {
                    //ʹ����С�ڵ������汻ɾ�ڵ㣬��ɾ������С�ڵ�
                    node* psuc = minimum(pnode->right);        //����������С�ڵ�
                    pnode->data = psuc->data;                                //����С�ڵ�ֵ���ǵ�ǰ���
                    pnode->right = remove_avl(pnode->right, psuc->data);    //�ݹ��ɾ����С�ڵ�
                }

            }
            else
            {
                node* ptemp = pnode;
                if (pnode->left != nullptr)
                    pnode = pnode->left;
                else if (pnode->right != nullptr)
                    pnode = pnode->right;
                delete ptemp;
                return nullptr;
            }

        }
        else if (key > pnode->data)//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ����������������ɾ��
        {
            pnode->right =  remove_avl(pnode->right, key);
            //ɾ���������ڵ㵼�²�ƽ��:�൱��������������
            if (height_avl(pnode->left) - height_avl(pnode->right) == 2)
            {
                //�൱�����������ϲ����ҽڵ���ɵ�ʧ�⣨����ģ�
                if (height_avl(pnode->left->right)>height_avl(pnode->left->left))
                    pnode = leftRightRotation(pnode);
                else//�൱�����������ϲ�����ڵ���ɵ�ʧ�⣨�������
                    pnode = rightRotation(pnode);
            }
        }
        else if (key < pnode->data)//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ�С����������������ɾ��
        {
            pnode->left= remove_avl(pnode->left, key);
             //ɾ���������ڵ㵼�²�ƽ�⣺�൱������������һ
            if (height_avl(pnode->right) - height_avl(pnode->left) == 2)
            {
                //�൱�����������ϲ�����ڵ���ɵ�ʧ�⣨�������
                if (height_avl(pnode->right->left)>height_avl(pnode->right->right))
                    pnode = rightLeftRotation(pnode);
                else//�൱�����������ϲ����ҽڵ���ɵ�ʧ�⣨���һ��
                    pnode = leftRotation(pnode);
            }
        }
        return pnode;
    }
    return nullptr;
}
BinaryTree::node* BinaryTree::maximum(node* pnode)
{
    if (pnode != nullptr)
    {
        while (pnode->right!= nullptr)
            pnode = pnode->right;
        return pnode;
    }
    return nullptr;
}
Type BinaryTree::maximum()
{
    node* presult = maximum(root);
    if (presult != nullptr)
        return presult->data;
}
BinaryTree::node* BinaryTree::minimum(node* pnode)
{
    if (pnode != nullptr)
    {
        while (pnode->left!= nullptr)
            pnode = pnode->left;
        return pnode;
    }
    return nullptr;
}
Type BinaryTree::minimum()
{
    node* presult = minimum(root);
    if (presult != nullptr)
        return presult->data;
}
BinaryTree::~BinaryTree()
{
    //dtor
    clear(root);
}
