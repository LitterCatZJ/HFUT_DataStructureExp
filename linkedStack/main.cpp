/**
 *Copyright:
 *This code is free software; you can redistribute it and/or modify
 *it under the terms of the GPL-3.0
 *
 * @author zhangjian
 * @date 2017.11
 *
 */

///////////////////////////////////////////////////////////////////////

#include<iostream>
#include "Stack.h"
#include <string>
using namespace std;

void dec2hex(int x);
bool is_match(string s);

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
    cout<<"������һ����ѧ���ʽ��";
    string s;
    cin>>s;
    cout<<boolalpha<<is_match(s)<<endl;



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
