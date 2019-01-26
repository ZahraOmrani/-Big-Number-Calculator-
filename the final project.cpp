#include <iostream>
#include <string>//53652269665777305600
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
       int data;
       node* next;
       };
class BigNumber
{ private:
	node* head;
	int sign;
	int len;
 public:
 	
	BigNumber mult(int);
	BigNumber addzero(int); 
		
	BigNumber();
	BigNumber(const BigNumber &);
	BigNumber(long num);
	BigNumber(long num,long digit);

    void print();

	BigNumber operator+( BigNumber);
	BigNumber operator=( BigNumber);
	BigNumber operator*(BigNumber);
	BigNumber operator-(BigNumber);
	
	int operator[](int);
	BigNumber operator-();

    BigNumber operator++();
	BigNumber operator++(int);
	BigNumber operator--();
	BigNumber operator--(int);
	
	BigNumber operator+=(BigNumber);
	BigNumber operator-=(BigNumber);
	BigNumber operator*=(BigNumber);
	
	bool operator==(const BigNumber &);
    bool operator<(const BigNumber &);
    bool operator>(const BigNumber &);
    bool operator<=(const BigNumber &z){return (  !(operator>(z)) ); }
	bool operator>=(const BigNumber &z){return (  !(operator<(z)) ); }
	

};

int main(void) 
{
BigNumber y(-9);
BigNumber x(-10);
cout << (x < y) << endl; 
//y=x;
//x.print();
//BigNumber(2,7).print();
//x[0];
//y.addzero(3).print();
//(y*x).print();
//cout<<(x>y);
//(x*y).print();
//(x-y).print()
//y=x.mult(2);
//(zxSy-x).print();
//z.print();
BigNumber z;
    for(int i=21;i>11;i--)
    {
    
    BigNumber p(1);
	for (int j = i; j > 0; j--)
	{
		p = p*j;
		
	}
	p.print();
    z=p+z;
    }
  z.print();     
 cout<<endl;
	return 0;
}
BigNumber::BigNumber()
{
    node* p;
    head =new node;
     p=head;
     head->data=0;
     head->next=NULL;
     len = 1;
 }
BigNumber::BigNumber(long num)
{
 	if (num<0)
 	{
 	
 	sign=-1;
 	num = -num;
 }
 	else
 	sign=1;
   	node* p;
     head =new node;
     p=head;
	 int r=num%10;
     head->data=r;
     head->next=NULL;
	 num=num/10;
	 len=1;
	 while(num>0)
	{   
        node* n=new node;
        p->next=n;
		r=num%10;
	    n->data=r;
	    len++;
	    n->next=NULL;
		num/=10;
		p = p->next;
	}
	
		
}
BigNumber::BigNumber(long num,long digit)
{
 	if (num<0)
 	{
 	
 	sign=-1;
 	num = -num;
 }
 	else
 	sign=1;
   	node* p;
     head =new node;
     p=head;
	 int r=num%10;
     head->data=r;
     head->next=NULL;
	 num=num/10;
	 len=1;
	 while(num>0)
	{   
        node* n=new node;
        p->next=n;
		r=num%10;
	    n->data=r;
	    len++;
	    n->next=NULL;
		num/=10;
		p = p->next;
	}

for(int i=1;i<=(digit-len+1);i++)
{
    	node* n=new node;
		len++;
        p->next=n;
	    n->data=0;
		n->next=NULL;
	    p=p->next;  
 }
}
BigNumber::BigNumber(const BigNumber &a)
{
	node* i;
	node* j;
	j=a.head;
	
	i = head = new node;
	i->data=j->data;
	j = j->next;
while(j!=NULL)
{  
    i->next=new node;
	i->next->data=j->data;
	j=j->next;
	i = i->next;	
}
i->next = NULL;
len = a.len;
}

void BigNumber::print(){
node* q;
q = head;
int i=0;
int* p=new int[len]; 
while(q!=NULL)
{
p[len-i-1]=q->data;
i++;
q=q->next;
}
if(sign==-1)
cout<<"-";
for (i=0; i<len-1 && p[i]==0; i++);

for ( ; i<len; i++)
	cout<<p[i];
cout << endl << "len = " << len << endl;
delete [] p;
}
 BigNumber BigNumber:: operator+( BigNumber x)
{ 
node* resP;
BigNumber res;
resP=res.head;
node* tP;
tP=head;
node* xP;
xP=x.head;
int buffer=0;

	int a=tP->data;
	int b=xP->data;
	int m=a+b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->data=m;
	tP=tP->next;
	xP=xP->next;


while(tP!=NULL&& xP!=NULL)
{   
	int a=tP->data;
	int b=xP->data;
	int m=a+b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	tP=tP->next;
	xP=xP->next;
	resP = resP->next;
	res.len++;
}

while(tP!=NULL)
{   
	int a=tP->data;
	int m=a+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	tP=tP->next;
	resP = resP->next;
	res.len++;
}
while(xP!=NULL)
{   

	int b=xP->data;
	int m=b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	xP=xP->next;
	resP = resP->next;
	res.len++;
}

if (buffer > 0)
{
	resP->next = new node;
	resP->next->data = buffer;
	
	resP = resP->next;
	res.len++;
}
resP->next=NULL;
return res;
}
BigNumber BigNumber:: operator=( BigNumber a)
{
	node* i;
	i=head;
	node* j;
	j=a.head;
	node *temp;
	while(i!=NULL){
		temp = i->next;
		
    delete i;
    	i = temp;
	}
	
	i = head = new node;
	i->data=j->data;
	j = j->next;
while(j!=NULL)
{  
    i->next=new node;
	i->next->data=j->data;
	j=j->next;
	i = i->next;	
}
i->next = NULL;
len = a.len;
return *this;
}
BigNumber BigNumber::operator++()
{
	return  *this=operator+(BigNumber(1));
	}
BigNumber BigNumber::operator++(int)
{
    BigNumber temp = *this;
	*this=operator+(BigNumber(1));
	return temp;

}
BigNumber BigNumber:: operator-()
{
	BigNumber temp=*this;
	if(sign==-1)
	sign=1;
	else
	sign=-1;
	return temp;
}
BigNumber BigNumber:: operator*(BigNumber x){
	BigNumber sum;
	node* r;
	r=head;
	node* k;
	k=x.head;
	node* p;
	p=sum.head;
	int i=0;
while (k!=NULL){
	int a=k->data;
    sum=sum+mult(a).addzero(i);
    i++;
	k=k->next;
}
return sum;
}
BigNumber BigNumber:: mult(int a)
{   
    BigNumber x;
    
	node* p;
	p=head;
	node* r;
    r=x.head;
	int buffer=0;
	int b=p->data;
	int m=b*a+buffer;
	buffer=m/10;
	m=m%10;
		
	x.head->data=m;

	p=p->next;	
	while(p!=NULL)
	{
		int b=p->data;
		int m=b*a+buffer;
		buffer=m/10;
		m=m%10;
		r->next=new node;
		r->next->data=m;
		p=p->next;
		r=r->next;	
		x.len++;
	}
	if (buffer!=0)
	{
		r->next=new node;
		r->next->data=buffer;
		r=r->next;
		x.len++;	
	}
	r->next=NULL;
	cout << "len = " << x.len << endl;
	return x;			
}
BigNumber BigNumber:: addzero(int z)
{
	BigNumber x(*this);
	for(int i=1;i<=z;i++){
		node* n=new node;
		n->data=0;	
		n->next=x.head;
		x.head=n;
		x.len++;
	}
	return x;
}	
BigNumber BigNumber:: operator-(BigNumber x)
{
if(sign==1 && x.sign==-1)
{
node* resP;
BigNumber res;
resP=res.head;
node* tP;
tP=head;
node* xP;
xP=x.head;
int buffer=0;

	int a=tP->data;
	int b=xP->data;
	int m=a+b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->data=m;
	tP=tP->next;
	xP=xP->next;


while(tP!=NULL&& xP!=NULL)
{   
	int a=tP->data;
	int b=xP->data;
	int m=a+b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	tP=tP->next;
	xP=xP->next;
	resP = resP->next;
	res.len++;
}

while(tP!=NULL)
{   
	int a=tP->data;
	int m=a+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	tP=tP->next;
	resP = resP->next;
	res.len++;
}
while(xP!=NULL)
{   

	int b=xP->data;
	int m=b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	xP=xP->next;
	resP = resP->next;
	res.len++;
}

if (buffer > 0)
{
	resP->next = new node;
	resP->next->data = buffer;
	
	resP = resP->next;
	res.len++;
}
resP->next=NULL;
res.sign=1;
return res;
}
if(sign==-1&&x.sign==1)
{
node* resP;
BigNumber res;
resP=res.head;
node* tP;
tP=head;
node* xP;
xP=x.head;
int buffer=0;

	int a=tP->data;
	int b=xP->data;
	int m=a+b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->data=m;
	tP=tP->next;
	xP=xP->next;


while(tP!=NULL&& xP!=NULL)
{   
	int a=tP->data;
	int b=xP->data;
	int m=a+b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	tP=tP->next;
	xP=xP->next;
	resP = resP->next;
	res.len++;
}

while(tP!=NULL)
{   
	int a=tP->data;
	int m=a+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	tP=tP->next;
	resP = resP->next;
	res.len++;
}
while(xP!=NULL)
{   

	int b=xP->data;
	int m=b+buffer;
 

    buffer=m/10;
    m=m%10;
 
	resP->next = new node;
	resP->next->data = m;
	xP=xP->next;
	resP = resP->next;
	res.len++;
}

if (buffer > 0)
{
	resP->next = new node;
	resP->next->data = buffer;
	
	resP = resP->next;
	res.len++;
}
resP->next=NULL;
res.sign=-1;
return res;
}
if(sign==-1&&x.sign==-1||sign==1&&x.sign==1)
{
	BigNumber z;
	node* r;
	r=head;
	node* k;
	k=x.head;
	node* p;
	p=z.head;
	int buffer=0;
int d;
int e=r->data+buffer;
if(k!=NULL) 
  { 
	 d=k->data;	
	 k=k->next;
}
else
    d=0;
	if(d<=e){
		z.head->data=e-d;
		buffer=0;
		}
	else{
		z.head->data=e+10-d;
		buffer=-1;		
	}	
r=r->next;
while(r!=NULL){
int d;
int e=r->data+buffer;
if(k!=NULL) 
  {
	 d=k->data;	
	 k=k->next;
}
else
    d=0;
	if(d<=e){
		p->next=new node;
		p->next->data=e-d;
		buffer=0;
		z.len++;
		}
	else{
		p->next=new node;
		p->next->data=e+10-d;
		buffer=-1;
		z.len++;		
	}
p=p->next;	
r=r->next;	
}
p->next=NULL;
if(operator>(x))
z.sign=1;
else
z.sign=-1;
return z;
}
}
BigNumber BigNumber::operator--()
{
	return *this=operator-(BigNumber(1));
}
BigNumber BigNumber::operator--(int)
{
	BigNumber temp = *this;
	*this=operator-(BigNumber(1));
	return temp;	
}
bool BigNumber::operator<(const BigNumber &z)
{    
 if((sign==1)&&(z.sign==1))
 {
	int maxLen = len>z.len?len:z.len;
	int* thisArrayForm=new int[maxLen]; 
	int* zArrayForm=new int[maxLen];
	
	 
	node* q;
	q = head;
	int i = maxLen-1;
	
	while(q!=NULL)
	{
		thisArrayForm[i]=q->data;
		i--;
		q=q->next;
	}

	for (int j=i; j>=0; j--)
		thisArrayForm[j]=0;
	i = maxLen - 1;
	node* p;
	p=z.head;
	while(p!=NULL)
	{
		zArrayForm[i]=p->data;
		i--;
		p=p->next;
	}
    bool ret;
	for (int j=i; j>=0; j--)
		zArrayForm[j]=0;

	   	for( i=0;i<maxLen && thisArrayForm[i]==zArrayForm[i];i++);

	   	if (i==maxLen)

	   		ret=false;
	   	else

	   ret=(thisArrayForm[i]< zArrayForm[i]);
	   	
	delete [] thisArrayForm;
	delete [] zArrayForm;
	return ret;
}
if((sign==-1)&&(z.sign==-1))
{
	 {
	int maxLen = len>z.len?len:z.len;
	int* thisArrayForm=new int[maxLen]; 
	int* zArrayForm=new int[maxLen];
	
	 
	node* q;
	q = head;
	int i = maxLen-1;
	
	while(q!=NULL)
	{
		thisArrayForm[i]=q->data;
		i--;
		q=q->next;
	}

	for (int j=i; j>=0; j--)
		thisArrayForm[j]=0;
	i = maxLen - 1;
	node* p;
	p=z.head;
	while(p!=NULL)
	{
		zArrayForm[i]=p->data;
		i--;
		p=p->next;
	}
    bool ret;
	for (int j=i; j>=0; j--)
		zArrayForm[j]=0;

	   	for( i=0;i<maxLen && thisArrayForm[i]==zArrayForm[i];i++);

	   	if (i==maxLen)

	   		ret=false;
	   	else

	   ret=(thisArrayForm[i]> zArrayForm[i]);
	   	
	delete [] thisArrayForm;
	delete [] zArrayForm;
	return ret;
}
}
 if( (sign==-1) && (z.sign==1) )
	       return true;
	    else
	       return false;
}
bool BigNumber::operator>(const BigNumber &z)
{
if((sign==1)&&(z.sign==1))
{
		int maxLen = len>z.len?len:z.len;
	int* thisArrayForm=new int[maxLen]; 
	int* zArrayForm=new int[maxLen];
	
	 
	node* q;
	q = head;
	int i = maxLen-1;
	
	while(q!=NULL)
	{
		thisArrayForm[i]=q->data;
		i--;
		q=q->next;
	}

	for (int j=i; j>=0; j--)
		thisArrayForm[j]=0;
	i = maxLen - 1;
	node* p;
	p=z.head;
	while(p!=NULL)
	{
		zArrayForm[i]=p->data;
		i--;
		p=p->next;
	}
    bool ret;
	for (int j=i; j>=0; j--)
		zArrayForm[j]=0;

	   	for( i=0;i<maxLen && thisArrayForm[i]==zArrayForm[i];i++);

	   	if (i==maxLen)

	   		ret=false;
	   	else

	   ret=(thisArrayForm[i]> zArrayForm[i]);
	   	
	delete [] thisArrayForm;
	delete [] zArrayForm;
	return ret;
}
if((sign==-1)&&(z.sign==-1))
{
	int maxLen = len>z.len?len:z.len;
	int* thisArrayForm=new int[maxLen]; 
	int* zArrayForm=new int[maxLen];
	
	 
	node* q;
	q = head;
	int i = maxLen-1;
	
	while(q!=NULL)
	{
		thisArrayForm[i]=q->data;
		i--;
		q=q->next;
	}

	for (int j=i; j>=0; j--)
		thisArrayForm[j]=0;
	i = maxLen - 1;
	node* p;
	p=z.head;
	while(p!=NULL)
	{
		zArrayForm[i]=p->data;
		i--;
		p=p->next;
	}
    bool ret;
	for (int j=i; j>=0; j--)
		zArrayForm[j]=0;

	   	for( i=0;i<maxLen && thisArrayForm[i]==zArrayForm[i];i++);

	   	if (i==maxLen)

	   		ret=false;
	   	else

	   ret=(thisArrayForm[i]<zArrayForm[i]);
	   	
	delete [] thisArrayForm;
	delete [] zArrayForm;
	return ret;	
}	

 if( (sign==-1) && (z.sign==1) )
	       return false;
	    else
	    return true;
    }

bool BigNumber::operator==(const BigNumber &z)
{   
 if((sign==-1)&&(z.sign==-1)||(sign==1)&&(z.sign==1))
{
	int maxLen = len>z.len?len:z.len;
	int* thisArrayForm=new int[maxLen]; 
	int* zArrayForm=new int[maxLen];
	
	 
	node* q;
	q = head;
	int i=0;
	
	while(q!=NULL)
	{
		thisArrayForm[maxLen-i-1]=q->data;
		i++;
		q=q->next;
	}

	for (int j=maxLen-i-2; j>=0; j--)
		thisArrayForm[j]=0;
	i=0;
	node* p;
	p=z.head;
	while(p!=NULL)
	{
		zArrayForm[maxLen-i-1]=p->data;
		i++;
		p=p->next;
	}

	for (int j=maxLen-i-2; j>=0; j--)
		zArrayForm[j]=0;
	
	int d=0;
	
	for( i=0;i<maxLen;i++){
	    	if(thisArrayForm[i]!=zArrayForm[i])
	    	return false;
	    	else
	    	d++;
			}
        if(d==maxLen)
	    	return true;

}

 if( (sign==-1) && (z.sign==1)||(sign==1) && (z.sign==-1) )
	       return false;
 }
BigNumber BigNumber::operator+=(BigNumber z)
{
BigNumber x=operator+(z);
*this = x;
 return x;	
}
BigNumber BigNumber::operator-=(BigNumber z)
{
BigNumber x=operator-(z);
*this = x;
 return x;		
}
BigNumber BigNumber::operator*=(BigNumber z)
{
BigNumber x=operator*(z);
*this = x;
 return x;		
}
int BigNumber::operator[](int a)
{
	node* q;
	q =head;
	int i=0;
	int* p=new int[len]; 
	while(q!=NULL)
	{
	p[len-i-1]=q->data;
	i++;
	q=q->next;
}
return p[a-1];	
}






