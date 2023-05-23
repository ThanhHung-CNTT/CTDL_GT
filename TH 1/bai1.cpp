//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
#include<iostream>
using namespace std;

struct node
{
	int data; 
	struct node *pNext; 
};
typedef struct node NODE; 


struct list
{
	NODE *pHead;
	NODE *pTail; 
};
typedef struct list LIST; 


void KhoiTao(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *KhoiTaoNODE(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
void ThemVaoDau(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; 
	}
	else
	{
		p->pNext = l.pHead; 
		l.pHead = p; 
	}
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
void ThemVaoCuoi(LIST &l, NODE *p)
{
	
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; 
	}
	else
	{
		l.pTail->pNext = p; 
		l.pTail = p; 
	}
}
void NhapDS(LIST &l){
    for (int i = 1;; i++)
	{
		int x;
		cout << "\nNhap x"<<i<<": ";
		cin >> x;
		NODE *p = KhoiTaoNODE(x); 
		ThemVaoCuoi(l, p);  
        if(x==0)  break;
	}
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
int DemSoLuong(LIST l){
    int Dem=0;
    for(NODE *k = l.pHead;k != NULL;k=k->pNext)
    {
        Dem++;
    }
    return Dem;
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
int TimMax(LIST l)
{
	int max = l.pHead->data; 
    NODE *h;
	for (NODE *k = l.pHead->pNext; k != NULL; k = k ->pNext)
	{
		if (max < k->data)
		{
			max = k->data;
		}
	}
	return max;
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
float Tinh_TBC(LIST l)
{
    int Tong=l.pHead->data;
    int n=1;
    float TBC;
    for(NODE *k=l.pHead->pNext; k!=NULL; k=k->pNext)
    {
        Tong= Tong+k->data;
        n++;
    }
    TBC= float(Tong/n);
    return TBC;
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
//Kiểm tra danh sách tăng dần
bool Kiemtra_Tang(LIST l){
    for(NODE *k = l.pHead;k->pNext != NULL;k=k->pNext)
    {
        if(k->data > k->pNext->data){
            return false;
        }
    }
    return true;
}

//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
void ThemGiatri_y_VaoSauCacGiatri_x(LIST &l, int x, int y)
{
	NODE *p = KhoiTaoNODE(y);
	NODE *q = KhoiTaoNODE(x);
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNODE(p->data);
				NODE *g = k->pNext; 
				h->pNext = g; 
				k->pNext = h; 
			}
		}
	}
}


//Ho ten: Nguyen Pham Thanh Hung
//MSSV: 6151071056
//Ngay sinh: 16/09/2002
//Email: 6151071056@st.utc2.edu.vn
int main()
{
	LIST l;
	KhoiTao(l); 
    NhapDS(l);
	cout << "\n\n\t DANH SACH PHAN TU: ";
	XuatDanhSach(l);
	cout << "\n\n\t GIA TRI LON NHAT: " << TimMax(l);
    cout << "\n\n\t TRUNG BINH CONG: " << Tinh_TBC(l)<<endl;
    cout << "\n\t SO LUONG PHAN TU: " << DemSoLuong(l)<<endl;
    if(Kiemtra_Tang(l)){
        cout<<"\n\t DAY TANG !!"<<endl;
    }
    else    cout<<"\n\t DAY KHONG TANG!!"<<endl;
	int y,x;
    cout<<"\nNhap gia tri y muon chen: ";
    cin>>y;
	cout << "\nNhap gia tri x de them y vao sau: ";
	cin >> x;
    ThemGiatri_y_VaoSauCacGiatri_x(l,x,y);
    XuatDanhSach(l);
	return 0;
}