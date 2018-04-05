#include<iostream>
#include "Stack.h"
#include<stack>
#include <string>
#include<fstream>
#include<sstream>
#include <cmath>
#include <cstring>
#include<vector>


using namespace std;

void dec2hex(int x);
bool is_match(string s);
double evaluate();
vector<string> split(string str,string pattern);
bool is_legal_output(int n,vector<int> a);
void all_legal_output(int i,int n,string s,stack<int> st);

int main()
{
//    <1>����˳��ջʵ�ֽ�10������ת��Ϊ16��������
//    ��һ�����ݣ�4
//    �ڶ������ݣ�11
//    ���������ݣ�254
//    ���������ݣ�1357
    cout<<" <1>����˳��ջʵ�ֽ�10������ת��Ϊ16��������"<<endl;
    int e1[]={4,11,254,1357};
    for(int i=0;i<sizeof(e1)/sizeof(e1[0]);i++)
    {
        cout<<"��"<<i+1<<"�����ݣ�"<<e1[i]<<endl;
        cout<<"ת��Ϊ16�������Ľ��Ϊ��";
        dec2hex(e1[i]);
    }
//    <2>��һ���Ϸ�����ѧ���ʽ��˵�����еĸ���С���š�{������}������[������]������(���͡�)��Ӧ���໥ƥ��ġ�
//    ����㷨�����ַ�����ʽ����ı��ʽS���ж����еĸ������Ƿ���ƥ��ġ�
    cout<<endl<<"<2>��һ���Ϸ�����ѧ���ʽ��˵�����еĸ���С���š�{������}������[������]����"<<endl
        <<    "��(���͡�)��Ӧ���໥ƥ��ġ�����㷨�����ַ�����ʽ����ı��ʽS���ж����еĸ������Ƿ���ƥ��ġ�"
        <<endl;

    string s;
    #ifdef IA
        cout<<"������һ����ѧ���ʽ��";
        cin>>s;
    #else
        s="[(1+2)*(3+4)]/2";
        cout<<"��ѧ���ʽΪ��"<<s<<endl;
    #endif // IA

    cout<<"�Ƿ�ƥ�䣺";
    cout<<boolalpha<<is_match(s)<<endl;

    cout<<endl<<"ջ����չʵ�飺"<<endl;
//    <1>����ջ����������Ϊ1��2��3��...��n������㷨ʵ�ֶԸ�����һ�����У��ж����Ƿ��Ǵ�ջ�Ϸ���������С�
//    <2>����ջ����������Ϊ1��2��3��...��n������㷨������п��ܵĳ�ջ���С�
//    <3>����ջ����������ʽ��ֵ��

    cout<<"<1>����ջ����������Ϊ1��2��3��...��n������㷨ʵ�ֶԸ�����һ�����У��ж����Ƿ��Ǵ�ջ�Ϸ���������С�"<<endl;
    #ifdef IA
        vector<int> e2;
        e2.push_back(0);//������n=1��ʼ����
        cout<<"����һ�����У�����-1�������룩��"<<endl;
        int x;
        cin>>x;
        while(x!=-1)
        {
            e2.push_back(x);
            cin>>x;
        }

    #else
        vector<int> e2={0,1,3,4,5,2};
    #endif // IA

    cout<<"����";
    for(int x : e2) if(x!=0) cout<<x<<' ';
    cout<<"�Ƿ�1~"<<e2.size()-1<<"�ĺϷ��������У�"<<endl;
    cout<<boolalpha<<is_legal_output(e2.size()-1,e2)<<endl<<endl;

    cout<<"<2>����ջ����������Ϊ1��2��3��...��n������㷨������п��ܵĳ�ջ���С�"<<endl;
    stack<int> st;
    int n;
    #ifdef IA
     cout<<"����n�Ĵ�С��";
     cin>>n;
    #else
        n=5;
    #endif // IA
    all_legal_output(1,n,"",st);
    cout<<endl;

    cout<<"<3>����ջ����������ʽ��ֵ��"<<endl;
//    cout<<"����һ���������ʽ��ֻ������С���ţ���"<<endl;
//    cin>>s;

    cout<<"������Ϊ��"<<evaluate()<<endl;

    return 0;
}

void dec2hex(int x)
{
    Stack<char> s;
    char m[]={'0','1','2','3','4','5','6','7','8','9','A','B',
                'C','D','E','F'};
    while(x)
    {
        s.push(m[x%16]);
        x/=16;
    }
    char temp;
    while(!s.isEmpty())
    {
        s.pop(temp);
        cout<<temp;
    }
    cout<<endl;
}
//�жϱ��ʽ�Ƿ�Ϸ�
bool is_match(string s)
{//����������ѹ��ջ��������������ջ��Ԫ��ƥ�䣬�����ַ�����
    Stack<char> st;
    for(char c : s)
    {
        char t;
        st.getTop(t);
        if(c=='[' || c=='{' || c=='(')
            st.push(c);
        else if(c==']'||c=='}'||c==')')
        {
            if((c==']'&&t=='[')||(c=='}'&&t=='{')||(c==')'&&t=='('))
               st.pop(t);//��ջ
            else return false;
        }
        else continue;
    }
    return true;

}
//˫ջ����ʽ
double evaluate()
{//����ջ��һ�������ȡʽ�ӵķ��ţ������������������������������в������������ű��档
    //��һ��ջ����ÿ�ζ��������֡�

    ifstream fin("H:/codes/console/seqList/exp.txt");
    if(!fin.is_open()){
        cout<<"open file failed"<<endl;
        exit(1);
    }
    stack<double> a;
    stack<string> b;
    string str;
    str="( 1 + ( ( 2 + 3 ) * ( sqrt ( 4 ) * 5 ) ) )";
    cout<<str<<endl;
    vector<string> exp=split(str," ");
    for(auto p=exp.begin();p!=exp.end();p++)
    {

        //cout<<str;
//        b.push(str);
        if(*p=="(") continue;
        else if(*p=="+") b.push(*p);
        else if(*p=="-") b.push(*p);
        else if(*p=="*") b.push(*p);
        else if(*p=="sqrt") b.push(*p);
        else if(*p==")")
        {
            string op=b.top();
            b.pop();// c++ÿ�γ�ջ��ȡ��ջ��Ԫ�أ�����ÿ��Ҫ��topȡ�����popɾ��ջ��Ԫ��
            double v=a.top();
            a.pop();
            if(op=="+")
            {
                v=a.top()+v;
                a.pop();
            }
            else if(op=="-")
            {
                v=a.top()-v;
                a.pop();
            }
            else if(op=="*")
            {
                v=a.top()*v;
                a.pop();
            }
            else if(op=="sqrt")
            {
                v=sqrt(v);
            }
            a.push(v);
        }
        else
        {
            char c[20];
            strcpy(c,(*p).c_str());
            a.push(atof(c));//��stringת��Ϊdouble�ĺ���atofֻ����char*���ͣ�������һ����stringת��Ϊchar*
        }
    }
    return a.top();
}
//�ָ��ַ�������
vector<string> split(string str,string pattern)
{
  string::size_type pos;
  vector<string> result;
  str+=pattern;//��չ�ַ����Է������
  int size=str.size();

  for(int i=0; i<size; i++)
  {
    pos=str.find(pattern,i);
    if(pos<size)
    {
      string s=str.substr(i,pos-i);
      result.push_back(s);
      i=pos+pattern.size()-1;
    }
  }
  return result;
}

bool is_legal_output(int n,vector<int> a)
{
    stack<int> s;
    int min=1,x;
    bool res=true;
    for(int i=1;i<=n;i++)
    {//����������е�ÿһ��Ԫ��
        x=a[i];
        if(x>=min)
        {
            for(int j=min;j<=x;j++)//��min~x�⼸��Ԫ����ջ
                s.push(j);
            s.pop();//��X��ջ
            min=x+1;//��ʱ��û����ջ����X+1~N��Щ��
        }
        else
        {
            if(s.top()!=x){
                res=false;
                break;
            }else
                s.pop();
        }
    }
    return res;
}
void all_legal_output(int i,int n,string s,stack<int> st)
{
    if(i>n) {//�ݹ����
        if(st.empty()) cout<<s<<endl;
        else{
            while(!st.empty())
            {
                stringstream sou;
                int t=st.top();
                st.pop();
                string ts;
                sou<<t;sou>>ts;
                 s+=ts;
            }
            cout<<s<<endl;//��ӡ���
        }
    }
    else{//ֱ��ѹ��ջ�����
        stack<int> st1(st);
        st1.push(i);
        all_legal_output(i+1,n,s,st1);
        //����0��st.size()���ܵ������
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            stack<int> st2(st);
             st2.push(i);
            string ts;
            stringstream sou;
            sou<<t;
            sou>>ts;
            s+=ts;
            all_legal_output(i+1,n,s,st2);
        }
    }
}
