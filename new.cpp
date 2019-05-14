#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;

struct stringMenu{
	char* data;
};

struct ngaysinh{
 int ngay, thang, nam;
};

struct sinhvien{
	int stt;
	char malop[30];
	char masv[30];
	char hoten[50];
 	struct ngaysinh ns;
	float diem;
};sinhvien sv[500];

int demSV= 0;
int x;
int y;
int c;
stringMenu menuMain[6];
stringMenu menuKeyTMHS[6];
stringMenu menuInDanhSach[3];
stringMenu menuSapXep[5];
stringMenu menuKey1[6];
stringMenu menuTimKiem[3];
stringMenu menuKey2[6];
stringMenu menuKey2_2[6];
stringMenu menuThongKe[3];

// Khai bao cac ham dung cho menu
void inNKiTuRaManHinh(char c, int soLuong);
void BangDataSV(int x, int y, int n);
void gotoxy(int x, int y);
int ThietKeChayMuiTen(stringMenu[],int);
void inMauDong(int,stringMenu[],int);
void showMenuMain();
void showMenuThemMoiHoSo();
void showMenuInDanhSach();
void showMenuSapXep();
void showMenuKey1();
void showMenuTimKiem();
void showMenuKey2();
void showMenuKey2_2();
void showMenuThongKe();
void in1SV();
void inSV();

// Khai bao cac ham kiem tra, chuan hoa va so sanh
bool KTNgaySinh(int ngay, int thang, int nam);
bool KTdiem(float diem);
char* ChuanHoaHoTen(char hoten[]);
char* TachHoTen(char HoTen[], char TenHo[]);
char* xoakhoangcach(char hoten[]);
char* xoakytu(char hoten[], int vt);
int SSDate(ngaysinh a, ngaysinh b);
int SSChuoi(char* sv1, char* sv2);
int SSTen(char *s1, char *s2);

//Khai bao cac ham dung voi file
void openfile();
void outfile();
void UpDateFile(sinhvien SV_update[], int n);

//Khai bao cac ham support
void swap(sinhvien &a, sinhvien &b);
void textcolor(int x);
void Nocursortype(); //an dau nhay chuot
void Nocursortype1(); //hien dau nhay chuot

//Khai bao ham sap xep nhanh
void SapXepDiemNhanh(sinhvien sv[], int left, int right);
void SapXepNSNhanh(sinhvien sv[], int left, int right);
void SapXepMSVNhanh(sinhvien sv[], int left, int right);
void SapXepMaLopNhanh(sinhvien sv[], int left, int right);
void SapXepHoTenNhanh(sinhvien sv[], int left, int right);

// Dinh nghia cac ham da khai bao

void inNKiTuRaManHinh(char c,int soLuong){
	for(int i=0;i<soLuong;i++)
		cout << c;
}

void BangDataSV(int x,int y,int n){
	x=30;
	y=1;
	int h=n*2+1;
	// 196 "-"
	for(int i=0;i<=h+2;i=i+2){
		gotoxy(x,y+i);
		inNKiTuRaManHinh(196,73+8);		
	}
	// 179 "|"
	for(int i=0;i<=h;i++){
		gotoxy(x,y+i);
		inNKiTuRaManHinh(179,1);
		gotoxy(x+5,y+i);
		inNKiTuRaManHinh(179,1);
		gotoxy(x+20,y+i);
		inNKiTuRaManHinh(179,1);
		gotoxy(x+20+15,y+i);
		inNKiTuRaManHinh(179,1);
		gotoxy(x+20+15+25,y+i);
		inNKiTuRaManHinh(179,1);
		gotoxy(x+20+15+25+12,y+i);
		inNKiTuRaManHinh(179,1);
		gotoxy(x+15+1+15+1+21+1+10+1+7+1+7+1,y+i);
		inNKiTuRaManHinh(179,1);
	}
	// 4 goc cua bang :(218-191-192-217)
	gotoxy(x,y);
	inNKiTuRaManHinh(218,1);
	gotoxy(x+73+8,y);
	inNKiTuRaManHinh(191,1);
	gotoxy(x,y+h+1);
	inNKiTuRaManHinh(192,1);
	gotoxy(x+73+8,y+h+1);
	inNKiTuRaManHinh(217,1);
	// ki tu -|- 193-194
	// hang 1 su dung 194
	gotoxy(x+5,y);
	inNKiTuRaManHinh(194,1);
	gotoxy(x+20,y);
	inNKiTuRaManHinh(194,1);
	gotoxy(x+20+15,y);
	inNKiTuRaManHinh(194,1);
	gotoxy(x+20+15+25,y);
	inNKiTuRaManHinh(194,1);
	gotoxy(x+20+15+25+12,y);
	inNKiTuRaManHinh(194,1);
	// hang cuoi (h+1) su dung 193
	gotoxy(x+5,y+h+1);
	inNKiTuRaManHinh(193,1);
	gotoxy(x+20,y+h+1);
	inNKiTuRaManHinh(193,1);
	gotoxy(x+20+15,y+h+1);
	inNKiTuRaManHinh(193,1);
	gotoxy(x+20+15+25,y+h+1);
	inNKiTuRaManHinh(193,1);
	gotoxy(x+20+15+25+12,y+h+1);
	inNKiTuRaManHinh(193,1);
	
	// ki tu |- va -\ 195 va 180
	
	for(int i=2;i<h;i=i+2){
		// tai cot 1
		gotoxy(x,y+i);
		inNKiTuRaManHinh(195,1);
		// tai cot cuoi 73
		gotoxy(x+73+8,y+i);
		inNKiTuRaManHinh(180,1);
	}
	// in + diem noi 197
	for(int i=2;i<h;i=i+2){
		gotoxy(x+5,y+i);
		inNKiTuRaManHinh(197,1);
		gotoxy(x+20,y+i);
		inNKiTuRaManHinh(197,1);
		gotoxy(x+20+15,y+i);
		inNKiTuRaManHinh(197,1);
		gotoxy(x+20+15+25,y+i);
		inNKiTuRaManHinh(197,1);
		gotoxy(x+20+15+25+12,y+i);
		inNKiTuRaManHinh(197,1);
	}
	// dien thong tin co ban
	
	gotoxy(x+1,y+1);
	cout << "STT";
	gotoxy(x+10,y+1);
	cout << "Ma lop";
	gotoxy(x+22,y+1);
	cout << "Ma sinh vien";
	gotoxy(x+44,y+1);
	cout << "Ho va ten";
	gotoxy(x+62,y+1);
	cout << "Ngay sinh";
	gotoxy(x+74,y+1);
	cout << "Diem TB";
	gotoxy(50,25);
	
	
}
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//void XoaManHinh()
//{
//	Gotoxy(17,3);cout<<setw(30)<< " ";Gotoxy(48,3);cout<<setw(20)<< " ";				
//	Gotoxy(17,6);cout<<setw(30)<< " ";Gotoxy(48,6);cout<<setw(20)<< " ";
//	Gotoxy(17,9);cout<<setw(30)<< " ";Gotoxy(48,9);cout<<setw(20)<< " ";
//	Gotoxy(17,12);cout<<setw(30)<< " ";Gotoxy(48,12);cout<<setw(20)<< " ";
//	Gotoxy(17,15);cout<<setw(30)<< " ";	Gotoxy(48,15);cout<<setw(20)<< " ";
//}

void Nocursortype() 
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Nocursortype1() 
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

bool KTNgaySinh(int ngay, int thang, int nam) {
    if (!((thang > 0 && thang <= 12 )&&(nam>=1900&&nam<=2016))) return false;
    else {
        switch (thang) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if (ngay > 31 || ngay < 1) return false;
                else return true;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (ngay < 1 || ngay > 30) return false;
                else return true;
                break;
            case 2:
                if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0)) {
                    if (ngay > 29 || ngay < 1) return false;
                    else return true;
                } else {
                    if (ngay > 28 || ngay < 1)return false;
                    else return true;
                }
                break;
        }
    }
}

bool KTdiem(float diem){
	if (!(diem>=0 && diem <=10)) return false;
	else{
		return true;
	}
}

char* xoakytu(char hoten[], int vt)
{
    int i, cd=strlen(hoten);//tinh toan do dai cua chuoi
    for(i=vt;i<cd;i++)
       hoten[i]=hoten[i+1];
       return hoten;
}
char* xoakhoangcach(char hoten[]){
	//Xoa khoang cach dau chuoi
    while(hoten[0]==' '){
    	hoten=xoakytu(hoten,0);
	} 
    //Xoa khoang cach o giua
    int cd=strlen(hoten)-1;
    for(int i=0;i<cd;i++)
    {
        while(hoten[i]==' '&&hoten[i+1]==' '&&i<cd){
        	hoten=xoakytu(hoten,i);
        	cd--;
    	}
    }
    //Xoa khoang cach cuoi
    int k=strlen(hoten)-1;
    while(hoten[k]==' ')
    {
        hoten[k]=0;
        k--;
    }
    return hoten;
}
char* ChuanHoaHoTen(char hoten[])
{
	int i=0;
	int n=strlen(hoten);

	while(i<n)
	{
		if((hoten[i]>='a')&&(hoten[i]<='z'))
			hoten[i]-=32;
		i++;
		while(hoten[i]!=' '&&i<n){
			if((hoten[i]>='A')&&(hoten[i]<='Z')){
				hoten[i]+=32;
				i++;
			}
			else{
				i++;
			}
		}
		if(i<n)
			i++;
		else 
			break;	 
	}
return hoten;
}
//Mo thong tin sinh vien tu file input.txt
void openfile()
{
	ifstream input;
	input.open("input.txt");
	input>>demSV;
	
	for(int i=0;i<demSV;i++)
	{
		input.get();
		input.getline(sv[i].malop, 30);
		input.getline(sv[i].masv, 30);
		input.getline(sv[i].hoten, 30);
	    input>>sv[i].ns.ngay>>sv[i].ns.thang>>sv[i].ns.nam;
		input>>sv[i].diem;
	}
	input.close();	
}
//luu thong tin sinh vien vao file output.txt
void outfile()
{
	ofstream output;
	output.open("danhsachsinhvien.txt");
	output<<"_________________________________DANH SACH SINH VIEN____________________________\n";
	output<<"________________________________________________________________________________\n";
	output<<"||     Ma lop    ||  Ma sinh vien ||      Ho va ten      ||Ngay sinh ||  DTB  ||\n";
	output<<"**---------------**---------------**---------------------**----------**-------**\n";
	for(int i=0;i<demSV;i++)
	{
		output<<"||"<<setw(15)<<left<<sv[i].malop<<"||"<<setw(15)<<left<<sv[i].masv<<"||"<<setw(21)<<left<<sv[i].hoten
              <<"||"<<setw(2)<<sv[i].ns.ngay<<"/"<<setw(2)<<sv[i].ns.thang<<"/"<<setw(4)<<sv[i].ns.nam
              <<"||"<<setw(7)<<sv[i].diem<<"||"<<endl; 
	}
	output<<"________________________________________________________________________________"<<endl;
	output.close();	
}

void UpDateFile(sinhvien SV_Update[], int n)
{
	ofstream filein;
	filein.open("input.txt",ios::out);
	filein<<n<<endl;
	
	for(int i=0;i<demSV;i++)
	{
		filein<<SV_Update[i].malop<<endl;
		filein<<SV_Update[i].masv<<endl;
		filein<<SV_Update[i].hoten<<endl;
		filein<<SV_Update[i].ns.ngay<<endl<<SV_Update[i].ns.thang<<endl<<SV_Update[i].ns.nam<<endl;
		filein<<SV_Update[i].diem<<endl;
	}						
}

void them()
{
	y=0;
	sinhvien SV;
	system("cls");
	Nocursortype1();
		
	for(int i=0; i < demSV; i++)
	{
		sv[i].stt = i+2;
		gotoxy(32,y+4);cout<<sv[i].stt;
	}
	
	BangDataSV(x,y,1);	
	fflush(stdin);
 	gotoxy(40,y+4);
	gets(SV.malop);	
	strupr(SV.malop);
	gotoxy(40,y+4); cout<<SV.malop;
	gotoxy(5,4);cout<<"Thanh cong";
					 
	do
	{
		gotoxy(53,y+4);
		gets(SV.masv);
		gotoxy(5,4);
		cout<<setw(18)<<" ";
		if(strlen(SV.masv)!=8)
		{
		gotoxy(5,4);
	  	cout<<"!!!MSV gom 8 ky tu"<<endl;
	  	gotoxy(53,y+4);
	  	cout<<setw(12)<<" ";	
		}   
	}while(strlen(SV.masv)!=8);
	
	for (int i=0; i < demSV; i++){
			int check = strcmp(sv[i].masv,SV.masv);
			gotoxy(5,4);
			cout<<setw(21)<<" ";
			if( check == 0){
				gotoxy(5,4);
				cout<<"!!!MSV nay da ton tai ";
				gotoxy(53,y+4);
	  			cout<<setw(12)<<" ";
	  			gotoxy(53,y+4);
	  			gets(SV.masv);
			}
		}	
	gotoxy(5,4);cout<<"Thanh cong";
		   		   	
	gotoxy(70,y+4);
	gets(SV.hoten);
    xoakhoangcach(SV.hoten);
    gotoxy(70,y+4);
    cout<<ChuanHoaHoTen(SV.hoten);
        
    do
    {
       	gotoxy(92,y+4);
		scanf("%d/%d/%d",&SV.ns.ngay,&SV.ns.thang,&SV.ns.nam);
		gotoxy(5,4);
		cout<<setw(16)<<" ";
		if(!KTNgaySinh(SV.ns.ngay,SV.ns.thang,SV.ns.nam))
		{
			gotoxy(5,4);
	 		cout<<"!!!Ngay sinh sai"<<endl;
	  		gotoxy(92,y+4);
	 		cout<<setw(10)<<" ";
		}
	}while(!KTNgaySinh(SV.ns.ngay,SV.ns.thang,SV.ns.nam));
	gotoxy(5,4);cout<<"Thanh cong";

	do
	{
		fflush(stdin);
		gotoxy(106,y+4);
		cin>>SV.diem;
		gotoxy(5,4);
		cout<<setw(20)<<" ";
		if(!KTdiem(SV.diem))
		{
			gotoxy(5,4);
	       	cout<<"!!!Diem khong hop le"<<endl;
	       	gotoxy(106,y+4);
	       	cout<<setw(5)<<" ";
	    }
	}while(!KTdiem(SV.diem));
	gotoxy(5,4);cout<<"Thanh cong";
		
	gotoxy(5,5);
	cout<<"An ESC de quay lai!";
	do
	{				
		c= getch();
	}while(c!=27);
	Nocursortype();
	sv[demSV++]=SV;
	UpDateFile(sv, demSV);
	showMenuMain();
}

void in1SV(sinhvien sv)
{
//	textcolor(12);
	gotoxy(40,y+4);cout<<sv.malop;
	gotoxy(53,y+4);cout<<sv.masv;
	gotoxy(70,y+4);cout<<sv.hoten;
	gotoxy(92,y+4);cout<<sv.ns.ngay<<"/"<<sv.ns.thang<<"/"<<sv.ns.nam;
	gotoxy(106,y+4);cout<<sv.diem;		
}

void inSV()
{
	y=0;
	for(int i=0;i<demSV;i++)
	{
		BangDataSV(x,y,demSV);
		gotoxy(32,y+4);cout<<i+1;
		gotoxy(40,y+4);cout<<sv[i].malop;
		gotoxy(53,y+4);cout<<sv[i].masv;
		gotoxy(70,y+4);cout<<sv[i].hoten;
		gotoxy(92,y+4);cout<<sv[i].ns.ngay<<"/"<<sv[i].ns.thang<<"/"<<sv[i].ns.nam;
		gotoxy(106,y+4);cout<<sv[i].diem;
		y+= 2;
	}
	Nocursortype();
}
int main(){
	
	openfile();
	// khai bao menu:
	Nocursortype();
	menuMain[0].data=(char*)" 1.Them moi ho so\n";
	menuMain[1].data=(char*)" 2.In danh sach\n";
	menuMain[2].data=(char*)" 3.Sap xep\n";
	menuMain[3].data=(char*)" 4.Tim kiem\n";
	menuMain[4].data=(char*)" 5.Thong ke\n";
	menuMain[5].data=(char*)" 6.Thoat";
		
	menuInDanhSach[0].data=(char*)"1.In danh sach ra file\n";
	menuInDanhSach[1].data=(char*)"2.In danh sach ra console\n";
	menuInDanhSach[2].data=(char*)"3.Quay lai";
	
	menuSapXep[0].data=(char*)"1.Chon\n";
	menuSapXep[1].data=(char*)"2.Chen\n";
	menuSapXep[2].data=(char*)"3.Noi bot\n";
	menuSapXep[3].data=(char*)"4.Nhanh\n";
	menuSapXep[4].data=(char*)"5.Quay lai";
		
	menuKey1[0].data=(char*)"1.ma sinh vien\n";
	menuKey1[1].data=(char*)"2.ma lop\n";
	menuKey1[2].data=(char*)"3.Ho va ten\n";
	menuKey1[3].data=(char*)"4.Ngay sinh\n";
	menuKey1[4].data=(char*)"5.Diem trung binh tich luy\n";
	menuKey1[5].data=(char*)"6.Quay lai";
	
	menuTimKiem[0].data=(char*)"1.Tuan tu\n";
    menuTimKiem[1].data=(char*)"2.Nhi phan\n";
    menuTimKiem[2].data=(char*)"3.Quay lai";
    
	menuKey2[0].data=(char*)"1.ma sinh vien\n";
	menuKey2[1].data=(char*)"2.ma lop\n";
	menuKey2[2].data=(char*)"3.Ho va ten\n";
	menuKey2[3].data=(char*)"4.Ngay sinh\n";
	menuKey2[4].data=(char*)"5.Diem trung binh tich luy\n";
	menuKey2[5].data=(char*)"6.Quay lai";
	
	menuKey2_2[0].data=(char*)"1.ma sinh vien\n";
	menuKey2_2[1].data=(char*)"2.ma lop\n";
	menuKey2_2[2].data=(char*)"3.Ho va ten\n";
	menuKey2_2[3].data=(char*)"4.Ngay sinh\n";
	menuKey2_2[4].data=(char*)"5.Diem trung binh tich luy\n";
	menuKey2_2[5].data=(char*)"6.Quay lai";
	
	menuThongKe[0].data=(char*)"1.Bao cao so luong sinh vien theo lop\n";
	menuThongKe[1].data=(char*)"2.Phan loai ket qua hoc tap\n";
	menuThongKe[2].data=(char*)"3.Quay lai";
	
	Nocursortype();
	showMenuMain();
}
void showMenuMain(){
	int t=ThietKeChayMuiTen(menuMain,6);
	switch(t){
		case 1:{
		    showMenuThemMoiHoSo();
			break;
		}
		case 2:{
		    showMenuInDanhSach();
			break;
		}
		case 3:{
			showMenuSapXep();
			break;
		}
		case 4:{
			showMenuTimKiem();
			break;
		}
		case 5:{
			showMenuThongKe();
			break;
		}
		default :{
			exit(0);
			break;
		}
	}
}
void showMenuThemMoiHoSo(){
		
	system("cls");Nocursortype1();		    
	them();						
}
void showMenuInDanhSach(){
	int t=ThietKeChayMuiTen(menuInDanhSach,3);
	switch(t){
		case 1:
		{
		    system("cls");
			cout<<"\nIn file thanh cong!";
			outfile();
			Sleep(1000);
			showMenuMain();
            break;
		}
		case 2:
		{
			system("cls");
			inSV();
			gotoxy(2,2);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuMain();
			break;
		}
		default:{
			showMenuMain();
			break;
		}
	}	
}
void showMenuKey1(){
	int t=ThietKeChayMuiTen(menuKey1,6);
	switch(t){
		case 1:{
			break;
		}
		case 2:{	
			break;
		}
		case 3:{
			break;
		}
		case 4:{	
			break;
		}
		case 5:{
			break;
		}
		default :{
			showMenuSapXep();
			break;
		}
	}
}
void swap(sinhvien &a, sinhvien &b)
{
	sinhvien temp =a;
	    a=b;
	    b=temp;
}

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

char* TachHoTen(char HoTen[],char TenHo[])  //HoTen la ten goc, TenHo la ten da dao
{
   int i,j=0,k,l;    //l va k se kep 2 vi tri dau va cuoi moi tu trong ten, i tim vi tri khoang trang, j chay trong chuoi ten moi
   k = strlen(HoTen);   //khoi tao ban dau cho k
   for(i=strlen(HoTen)-1;i>=-1;i--) //Cho i chay tu phan tu cuoi den dau trong chuoi ten goc
      if((HoTen[i]==' ') || (i==-1))    //Neu tim dc khoang trang hoac den dau chu0i
      {  for(l=i+1;l<k;l++)    //Sao chep tu nay vao chuoi ten moi
         {   TenHo[j]=HoTen[l];
              j++;
         }
         if(i!=-1)        //Neu chua ket thuc
         {    TenHo[j]=' ';
               j++;    //Vi tri dau tien cua tu tiep theo chen vao chuoi moi
         }
         k=strlen(HoTen)-j;   //khoi to gia tri k moi, tiep tuc vong lap tim khoang trang va tim l moi
     }
   TenHo[j]='\0';
   return TenHo;
}
int SSDate(ngaysinh a, ngaysinh b)
{
	if(a.nam<b.nam) return -1;
	if(a.nam>b.nam) return  1;
	if(a.thang<b.thang) return -1;
	if(a.thang>b.thang) return  1;
	if(a.ngay<b.ngay) return -1;
	if(a.ngay>b.ngay) return  1;
	return 0;
}
void SapXepNSNhanh( sinhvien sv[], int left, int right){
	if(left<right){
	int i=left, j=right;		
	ngaysinh k=sv[(left+right)/2].ns;	
		while(SSDate(sv[i].ns,k)==-1){
			i++;
		}
		while(SSDate(sv[j].ns,k)==1){
			j--;
		}
		if(i<=j){
			swap(sv[i], sv[j]);
			i++;
			j--;
		}	
		SapXepNSNhanh(sv, left, j);
		SapXepNSNhanh(sv, i, right);
	}
}

int SSChuoi(char* sv1, char* sv2)
{
	if(strcmp(sv1, sv2)<0) return -1;
	if(strcmp(sv1, sv2)>0) return 1;
	return 0;
}

void SapXepMSVNhanh(sinhvien sv[], int left, int right)
{
	if(left<right){
	int i=left, j=right;		
	char* r=sv[(left+right)/2].masv;
	
	if(i<j)
	{
			while(SSChuoi(sv[i].masv,r)== -1) i++;
		while(SSChuoi(sv[j].masv,r)== 1) j--;
		if(i<=j){
			swap(sv[i], sv[j]);
			i++;
			j--;
		}
	}	
		SapXepMSVNhanh(sv, left, j);
		SapXepMSVNhanh(sv, i, right);
	}
}

void SapXepMaLopNhanh(sinhvien sv[], int left, int right)
{
	if(left<right){
	int i=left, j=right;		
	char* r=sv[(left+right)/2].malop;
	if(i<j)
	{
		while(SSChuoi(sv[i].malop,r)== -1) i++;
		while(SSChuoi(sv[j].malop,r)== 1) j--;
		if(i<=j){
			swap(sv[i], sv[j]);
			i++;
			j--;
		}
	}		
		SapXepMaLopNhanh(sv, left, j);
		SapXepMaLopNhanh(sv, i, right);
	}
}

int SSTen(char *s1, char *s2)
{
	char *x,*y;
	// di chuyen con tro x, y den vi tri dau cua ten
	x=s1+strlen(s1)-1;
	while(*x!=' ') x=x-1; x++;
	y=s2+strlen(s2)-1;
	while(*y!=' ') y=y-1; y++;
	int i=strcmp(x,y); // so sanh ten
	if(i<0) return -1;
	if(i>0) return 1;
	
	// cho con tro x, y chuyen den ho cua ten
	x=s1; y=s2;
	i=strcmp(x,y); // so sanh ho, ten dem, ten 
	if(i<0) return -1;
	if(i>0) return 1;
	return 0;
}

void SapXepHoTenNhanh(sinhvien sv[], int left, int right)
{
	if(left<right){
	int i=left, j=right;		
	char* r=sv[(left+right)/2].hoten;
	do{
		while(SSTen(sv[i].hoten,r)==-1) i++;
		while(SSTen(sv[j].hoten,r)==1) j--;
		if(i<=j){
			swap(sv[i], sv[j]);
			i++;
			j--;
		}
	}while(i<j);
		SapXepHoTenNhanh(sv, left, j);
		SapXepHoTenNhanh(sv, i, right);
	}
}

void SapXepDiemNhanh(sinhvien sv[], int left, int right){
	if (left<right){
	int i=left, j=right;
	float pivot=sv[(left+right)/2].diem;
	do{
		while(sv[i].diem<pivot) i++;
		while(sv[j].diem>pivot) j--;
		if(i<=j){
			swap(sv[i],sv[j]);
			i++;
			j--;
		}
	}while(i<j);
		SapXepDiemNhanh(sv,left,j);
		SapXepDiemNhanh(sv,i,right);
	}
}
void showMenuSapXep(){
	int t=ThietKeChayMuiTen(menuSapXep,5);
			        switch(t)
			        {
			        	 	// sap xep chon
			        	case 1:{ 
//							1.Sap xep theo ma sinh vien 
//    						2.Sap xep theo ma lop
//    						3.Sap xep theo ho va ten 
//    						4.Sap xep theo ngay sinh
//    						5.Sap xep theo diem trung binh tich luy
//    						6.Thoat
    						int t1=ThietKeChayMuiTen(menuKey1,6);
			        			switch(t1)
			        			{
			        				case 1:{
			        					system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int i,j,min;
				                           for ( i = 0; i < demSV-1; i++)
 				                              {
	 			                                min=i;
   					                             for (int j = i+1; j < demSV; j++)
					                                  if (strcmp(sv[min].masv , sv[j].masv  )>0) 
		 			                                 min = j;
    				                                  swap(sv[min], sv[i]);
 				                                    }
 				                                    inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 2:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int i,j,min;
				                           for ( i = 0; i < demSV-1; i++)
 				                                {
	 			                                min=i;
   					                            for (int j = i+1; j < demSV; j++)
					                                if (strcmp(sv[min].malop , sv[j].malop  )>0) 
		 			                                	min = j;
    				                                    swap(sv[min], sv[i]);
 				                            	}
 				                                inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 3:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int x;
										char HoTen1[30] = " ";
	                                    char HoTen2[30] = " ";
			                            sinhvien t;
  			                                for (int i = 1; i < demSV; i++)
  			                                {	
   				                                x = i - 1; 			
   				                                t = sv[i]; 	
											    TachHoTen(sv[i-1].hoten,HoTen1);
			                                    TachHoTen(sv[i].hoten,HoTen2);		
   				                            while (x >= 0 && strcmp( HoTen1 , HoTen2  ) >0 )
   				                                {
      				                                sv[x + 1] = sv[x];
     				                                x--;
   				                                }
   					                                sv[x + 1] = t; 
  			                                    }
  			                                   
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 4:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										for (int i = 0; i < demSV-1; i++)
 	                                        {
   		                                        int min = i;
   		                                        for (int j = i+1; j < demSV; j++)
   		                                            {
		 	                                            if (sv[min].ns.nam > sv[j].ns.nam) 
		 	                                        {
			                                            min = j;
			                                            }
    		                                            else if(sv[min].ns.nam == sv[j].ns.nam)
    		                                            {
    			                                            if(sv[min].ns.thang > sv[j].ns.thang)
    			                                                {
    			                                  	                min=j;
				                                                }
				                                            else if(sv[min].ns.thang == sv[j].ns.thang)
				                                                {
					                                        if(sv[min].ns.ngay > sv[j].ns.ngay)
					                                            {
						                                            min=j;
					                                            }
				                                                }
			                                            }
  		                                            }
  		                                                swap(sv[i],sv[min]);
 	                                            }
  		                                        inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 5:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int min,temp;
	                                        for(int i=0;i<demSV-1;i++){
		                                    min=i;
		                                        for(int j=i+1;j<demSV;j++){
			                                    if(sv[j].diem<sv[min].diem) min=j;
		                                        }
		                                        if(min!=i){
			                                    swap(sv[i],sv[min]);
		                                    }
	                                    }
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									default:{
										showMenuSapXep();
										break ;
									}
								}
						}
						// sap xep chen
						case 2:{
//							1.Sap xep theo ma sinh vien 
//    						2.Sap xep theo ma lop
//    						3.Sap xep theo ho va ten 
//    						4.Sap xep theo ngay sinh
//    						5.Sap xep theo diem trung binh tich luy
//    						6.Thoat 
    						int t2=ThietKeChayMuiTen(menuKey1,6);
			        			switch(t2)
			        			{
			        				case 1:{
			        					system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int x;
			                            sinhvien t;
  			                                for (int i = 1; i < demSV; i++)
  			                                {
   				                                x = i - 1; 			
   				                                t = sv[i]; 			
   				                                while (x >= 0 && strcmp( sv[x].masv , t.masv  ) >0 )
   				                                    {
      				                                    sv[x + 1] = sv[x];
     				                                    x--;
   				                                    }
   					                                    sv[x + 1] = t; 
  			                                }
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 2:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int x;
			                            sinhvien t;
  			                                for (int i = 1; i < demSV; i++)
  			                                {
   				                                x = i - 1; 			
   				                                t = sv[i]; 			
   				                                while (x >= 0 && strcmp( sv[x].malop , t.malop  ) >0 )
   				                                {
      				                                sv[x + 1] = sv[x];
     				                                x--;
   				                                }
   					                                sv[x + 1] = t; 
  			                                    }
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 3:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int x;
										char HoTen1[30] = " ";
	                                    char HoTen2[30] = " ";
			                            sinhvien t;
  			                                for (int i = 1; i < demSV; i++)
  			                                {	
   				                                x = i - 1; 			
   				                                t = sv[i]; 	
											    TachHoTen(sv[i-1].hoten,HoTen1);
			                                    TachHoTen(sv[i].hoten,HoTen2);		
   				                            while (x >= 0 && strcmp( HoTen1 , HoTen2  ) >0 )
   				                                {
      				                                sv[x + 1] = sv[x];
     				                                x--;
   				                                }
   					                                sv[x + 1] = t; 
  			                                    }
  			                                   
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 4:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int x;
	                                       sinhvien t;
  	                                            for (  int i = 1; i < demSV; i++)
  	                                                {
   		                                                x = i - 1; 			
   		                                                t = sv[i]; 
		                                                if(sv[x].ns.nam > t.ns.nam)	
		                                                {		
   			                                            while (x >= 0 && sv[x].ns.nam > t.ns.nam)
   				                                        {
      				                                        sv[x + 1] = sv[x];
     				                                        x--;
   				                                        }	
   					                                        sv[x + 1] = t; 
   		                                                }
   		                                                    else if (sv[x].ns.nam == t.ns.nam)
   		                                                    {
   			                                                    if(sv[x].ns.thang > t.ns.thang)
   			                                                    {		
   			                                                        while (x >= 0 && sv[x].ns.thang > t.ns.thang)
   				                                                {
      				                                                sv[x + 1] = sv[x];
     				                                                x--;
   				                                                }	
   				 	                                                sv[x + 1] = t; 
			                                                    }
			                                                    else if(sv[x].ns.thang == t.ns.thang)
			                                                        {
				                                                    if(sv[x].ns.ngay> t.ns.ngay)
				                                                    {
					                                                while (x >= 0 && sv[x].ns.ngay > t.ns.ngay)
   					                                                    {
      					                                                    sv[x + 1] = sv[x];
     					                                                    x--;
   			 		                                                    }	
   						                                                    sv[x + 1] = t;
				                                                    }
			                                                        }	
		                                                    }
   				
  	                                                }
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 5:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										int temp,j;
	                                    for(int i=1;i<demSV;i++){
		                                    temp=sv[i].diem; j=i-1;
		                                    while(j>=0 && temp<sv[j].diem){
			                                    sv[j+1].diem=sv[j].diem;
			                                    j--;
		                                        }
		                                            sv[j+1].diem=temp;
	                                                            }
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									default:{
										showMenuSapXep();
										break;
								}
							}
						}
						//sap xep noi bot
						case 3:{
//							1.Sap xep theo ma sinh vien 
//    						2.Sap xep theo ma lop
//    						3.Sap xep theo ho va ten 
//    						4.Sap xep theo ngay sinh
//    						5.Sap xep theo diem trung binh tich luy
//    						6.Thoat 
    						int t3=ThietKeChayMuiTen(menuKey1,6);	
			        			switch(t3)
			        			{
			        				case 1:{
			        					system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										for (int i = demSV-1; i > 0; i--) {
				                            for (int j = 0; j < i; j++) {
					                            if (strcmp( sv[j].masv , sv[j+1].masv  )>0) {
						                        swap(sv[j], sv[j+1]);
					                                        }
				                                       }
			                                       }
			                                inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 2:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										for (int i = demSV-1; i > 0; i--) {
				                            for (int j = 0; j < i; j++) {
					                        if (strcmp( sv[j].malop , sv[j+1].malop  )>0) {
						                        swap(sv[j], sv[j+1]);
					                                        }
				                                       }
			                                       }
			                                inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 3:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										char HoTen1[30] = " ";
	                                    char HoTen2[30] = " ";
	                                        for (int i = demSV-1; i > 0; i--){	
		                                        for (int j = 0; j < i; j++){
			                                        TachHoTen(sv[j].hoten,HoTen1);
			                                        TachHoTen(sv[j+1].hoten,HoTen2);
			                                        int check1 = strcmp(HoTen1,HoTen2);
			                                        if(check1>0){
				                                    swap(sv[j],sv[j+1]);
									                }
									            }
								        	}
								        	inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
								       }
									case 4:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										for (int i = demSV-1; i > 0; i--) {
			                                for (int j = 0; j < i; j++) {
				                                if(sv[j].ns.nam > sv[j+1].ns.nam)
				                                {
					                                swap(sv[j],sv[j+1]);
				                                }
			 	                                else if(sv[j].ns.nam == sv[j+1].ns.nam)
				                                {
					                                if(sv[j].ns.thang > sv[j+1].ns.thang)
					                               {
						                                swap(sv[j],sv[j+1]);
					                                  }
					                                    else if(sv[j].ns.thang== sv[j+1].ns.thang)
					                                    {
						                                    if(sv[j].ns.ngay > sv[j+1].ns.ngay)
						                                        {
							                                        swap(sv[j],sv[j+1]);
						                                            }
					                                        }
				                                    }
			                                }
		                                }
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 5:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										for(int i=0;i<demSV-1;i++){
		                                    for(int j=demSV-2;j>=i;j--){
			                                    if(sv[j].diem>sv[j+1].diem){
				                                   swap(sv[j],sv[j+1]);				
			                                                 }
		                                                 }
	                                            }	
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									default:{
										showMenuSapXep();
										break;
								    }
							}
						}					
						//sap xep nhanh
						case 4:{
//							1.Sap xep theo ma sinh vien 
//    						2.Sap xep theo ma lop
//    						3.Sap xep theo ho va ten 
//    						4.Sap xep theo ngay sinh
//    						5.Sap xep theo diem trung binh tich luy
//    						6.Thoat 
    						int t4=ThietKeChayMuiTen(menuKey1,6), n;	
			        			switch(t4)
			        			{
			        				case 1:{
			        					system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										SapXepMSVNhanh(sv, 0, demSV-1);
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 2:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										SapXepMaLopNhanh(sv, 0, demSV-1);
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 3:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										SapXepHoTenNhanh(sv, 0, demSV-1);
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 4:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										SapXepNSNhanh(sv, 0, demSV-1);
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									case 5:{
										system("cls");
										cout<<"Danh sach sau khi sap xep\n";
										SapXepDiemNhanh(sv,0, demSV-1);
										inSV();
										gotoxy(5,5);
										cout<<"An ESC de quay lai!";
										do
										{				
											c= getch();
										}while(c!=27);
										showMenuKey1();
										break;
									}
									default:{
										showMenuSapXep();
										break;
								}
							}				
}
default:{
	showMenuMain();
    break;
   }
 }
}
void showMenuTimKiem(){
	int t=ThietKeChayMuiTen(menuTimKiem,3);
	switch(t){
		case 1:{
			showMenuKey2();	
			break;
		}
		case 2:{
			showMenuKey2_2();	
			break;
		}
		default :{
			showMenuMain();
			break;
		}
	}
}

void showMenuKey2(){
	int t=ThietKeChayMuiTen(menuKey2,6);
	switch(t){
		case 1:{
			system("cls"); Nocursortype1();
			char ma_sv[30];
	        int dem=0;
            cout<<"Nhap MSV can tim: ";
            gets(ma_sv);
            char* p;
      		y = 0;      
            for(int i=0;i<demSV;i++){       	
            	p = strstr(sv[i].masv,ma_sv);
				if (p != NULL)
                {
                	BangDataSV(x,y,dem+1);
					textcolor(12);             	
                	sv[i].stt = i+1;
					gotoxy(32,y+4);cout<<sv[i].stt;	               		               	
	             	in1SV(sv[i]);
	            	dem++;
	            	y+= 2;
            	}
	        } 
            if(!dem){
             	gotoxy(1,2);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,3);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
		case 2:{
	     	system("cls"); Nocursortype1();
       		char ma_lop[30];
	        int dem=0;
            cout<<"\nNhap ma lop can tim: ";
            gets(ma_lop);
            char* p;
            y = 0;
            for(int i=0;i<demSV;i++){
            	p = strstr(sv[i].malop,ma_lop);
                if (p != NULL)
                {
                	sv[i].stt = i+1;
					gotoxy(32,y+4);cout<<sv[i].stt;
	               	BangDataSV(x,y,dem+1);
	             	in1SV(sv[i]);           	
	             	dem++;
	             	y+= 2;
            	}   				       	
        	}
					 
			if(!dem){
             	gotoxy(1,2);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,3);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);      
			showMenuTimKiem();
			break;
		}
		case 3:{
			system("cls");
			char ho_ten[30]; Nocursortype1();
        	int dem=0;
        	fflush(stdin);
            cout<<"\nNhap ho ten can tim kiem: "<<endl;
            gets(ho_ten);
            char* p;
    		y = 0;
            for(int i=0;i<demSV;i++){
            	p = strstr(sv[i].hoten, ho_ten);
                if (p != NULL)
                {
                	sv[i].stt = i+1;
					gotoxy(32,y+4);cout<<sv[i].stt;
	               	BangDataSV(x,y,dem+1);
	             	in1SV(sv[i]);           	
	             	dem++;
	             	y+= 2;
            	}          	
        	}               
            if(!dem){
             	gotoxy(1,3);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,4);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
		case 4:{
			system("cls"); Nocursortype1();
	    	int ngay_,thang_,nam_;
         	int dem=0;
        	cout<<"Nhap ngay sinh can tim kiem: ";
        	cout<<"\nNgay: ";cin>>ngay_;
        	cout<<"\nThang: ";cin>>thang_;
        	cout<<"\nNam: ";cin>>nam_;
    		y = 0;
        	for(int i=0;i<demSV;i++){
	         	if(sv[i].ns.ngay==ngay_&&sv[i].ns.thang==thang_&&sv[i].ns.nam==nam_)
	        	{
	        		sv[i].stt = i+1;
					gotoxy(32,y+4);cout<<sv[i].stt;
		        	BangDataSV(x,y,dem+1);
			    	in1SV(sv[i]);
			    	dem++;
			    	y+= 2;
	        	}
         	}
            if(!dem){
             	gotoxy(1,8);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,9);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
		case 5:{
			system("cls"); Nocursortype1();
			int diem_;
        	int dem=0;
            cout<<"\nNhap diem can tim: ";
            cin>>diem_;
    		y = 0;
            for(int i=0;i<demSV;i++){           	
                if (sv[i].diem==diem_)
                {
                	sv[i].stt = i+1;
					gotoxy(32,y+4);cout<<sv[i].stt;
                	BangDataSV(x,y,dem+1);
	             	in1SV(sv[i]);
	            	dem++;	
					y+= 2;				
            	}          	
        	}  
        	
            if(!dem){
             	gotoxy(1,3);
	         	cout<<"sinh vien khong ton tai!";
         	}             	
			gotoxy(1,4);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
		default :{
			showMenuTimKiem();
			break;
		}
	}
}
void showMenuKey2_2(){
    int t=ThietKeChayMuiTen(menuKey2,6);
	switch(t){
		case 1:{
			system("cls");Nocursortype1();			
			char msv_[30];
			int pivot;
			int left=0;
			int right=demSV-1;
	        int dem=0;
	        y=0;
        	for (int i = 0; i < demSV-1; i++) {    
	        for (int j = i+1; j < demSV; j++) {
		    	if (strcmp(sv[i].masv, sv[j].masv)>0 ) {
		 			swap(sv[i],sv[j]);
		              } 
	             }
            }
        	cout<<"Nhap MSV can tim: ";
        	gets(msv_);  
			    	
        	while(left<=right)
			{
	        	pivot= (left+right)/2;
	    	if(strcmp(msv_,sv[pivot].masv)<0) {
	            right=pivot-1;  
	    	}
	    	else if(strcmp(msv_,sv[pivot].masv)>0){
		    	left=pivot+1;
	    	}
	    	else
	         	if(strcmp(msv_,sv[pivot].masv)==0)
	        	{
					sv[pivot].stt = pivot+1;
					gotoxy(32,y+4);cout<<sv[pivot].stt;	        		
	        		BangDataSV(x,y,dem+1);
		        	in1SV(sv[pivot]);
		        	dem++;
		        	//y+=2;
		        	break;
               	}
           	}
            
        	if(!dem){
             	gotoxy(1,2);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,3);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
	    	}
		case 2:{
			system("cls"); Nocursortype1();			
			char malop_[30];
			int pivot;
			int left=0;
			int right=demSV-1;
	        int dem=0;
	        y=0;
        	for (int i = 0; i < demSV-1; i++) {    
	        for (int j = i+1; j < demSV; j++) {
		    	if (strcmp(sv[i].malop, sv[j].malop)>0 ) {
		 			swap(sv[i],sv[j]);
		              } 
	             }
            }
        	cout<<"Nhap ma lop can tim: ";
        	gets(malop_);	        
        	while(left<=right)
			{
	        	pivot= (left+right)/2;
		
	    	if(strcmp(malop_,sv[pivot].malop)<0) {
	            right=pivot-1;  
	    	}
	    	else if(strcmp(malop_,sv[pivot].malop)>0){
		    	left=pivot+1;
	    	}
	    	else
	         	if(strcmp(malop_,sv[pivot].malop)==0)
	        	{
	        		sv[pivot].stt = pivot+1;
					gotoxy(32,y+4);cout<<sv[pivot].stt;
		       		BangDataSV(x,y,dem+1);
		        	in1SV(sv[pivot]);
		        	dem++;
		        	break;
               	}
           	}
            if(!dem){
             	gotoxy(1,2);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,3);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
		case 3:{
			system("cls");Nocursortype1();			
			char hoten_[30];
			int pivot;
			int left=0;
			int right= demSV-1;
	        int dem=0;
	        y=0;
	        for (int i = 0; i < demSV-1; i++){	
		        for (int j = i+1; j < demSV; j++){
			        if(strcmp(sv[i].hoten,sv[j].hoten)>0){
				        swap(sv[i],sv[j]);
								}
						 	}
						}
        	cout<<"Nhap ho ten can tim: "<<endl;
        	gets(hoten_);	        
        	while(left<=right)
			{      		
	        	pivot= (left+right)/2;
		
	    	if(strcmp(hoten_,sv[pivot].hoten)<0) {
	            right=pivot-1;  
	    	}
	    	else if(strcmp(hoten_,sv[pivot].hoten)>0){
		    	left=pivot+1;
	    	}
	    	else
	         	if(strcmp(hoten_,sv[pivot].hoten)==0)
	        	{
	        		sv[pivot].stt = pivot+1;
					gotoxy(32,y+4);cout<<sv[pivot].stt;
		        	BangDataSV(x,y,dem+1);
		        	in1SV(sv[pivot]);
		        	dem++;
		        	break;
               	}
           	}
            if(!dem){
             	gotoxy(1,3);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,4);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
		case 4:{
			system("cls");Nocursortype1();			
//			int ngay_, thang_, nam_;
			int nam_;
			int pivot;
			int left=0;
			int right=demSV-1;
	        int dem=0;
	        y=0;
        	for (int i = demSV-1; i > 0; i--)
			{
	        for (int j = 0; j < i; j++)
				{  
			        if(sv[j].ns.nam > sv[j+1].ns.nam)
				   	{
					   	swap(sv[j],sv[j+1]);
				    }
			 	    else if(sv[j].ns.nam == sv[j+1].ns.nam)
				    {
					    if(sv[j].ns.thang > sv[j+1].ns.thang)
					    {
						    swap(sv[j],sv[j+1]);
					    }
					    else if(sv[j].ns.thang== sv[j+1].ns.thang)
					    {
						    if(sv[j].ns.ngay > sv[j+1].ns.ngay)
							{
							    swap(sv[j],sv[j+1]);
						    }
					    }
				    }
			    }
		    }
        	cout<<"Nhap ngay sinh can tim: "<<endl;
//        	cout<<"\nNgay: "; cin>>ngay_; cout<<"\nThang: "; cin>>thang_; cout<<"\nNam: "; cin>>nam_;
			cout<<"\nNam: "; cin>>nam_;
	        
        	while(left<=right){
	        	pivot= (left+right)/2;
		
	    	if(nam_< sv[pivot].ns.nam /*&& thang_< sv[pivot].ns.thang && ngay_< sv[pivot].ns.ngay*/) {
	            right=pivot-1;  
	    	}
	    	else if(nam_>sv[pivot].ns.nam /*&& thang_> sv[pivot].ns.thang && ngay_> sv[pivot].ns.ngay*/) {
	            left= pivot+1;  
	    	}
	    	else if(nam_== sv[pivot].ns.nam /*&& thang_== sv[pivot].ns.thang && ngay_== sv[pivot].ns.ngay*/)
	        	{
	        		sv[pivot].stt = pivot+1;
					gotoxy(32,y+4);cout<<sv[pivot].stt;
	        		BangDataSV(x,y,dem+1);
		        	in1SV(sv[pivot]);
		        	dem++;
		        	//break;
               	}
            if(!dem){
             	gotoxy(1,8);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,9);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
	}
		case 5:{
			system("cls");Nocursortype1();			
			float diem_;
			int pivot;
			int left= 0;
			int dem = 0;
			int right= demSV-1;
	        y=0;
        	for (int i = 0; i < demSV-1; i++) {    
	        for (int j = i+1; j < demSV; j++) {
		    	if (sv[i].diem > sv[j].diem ) {
		 			swap(sv[i],sv[j]);
		              } 
	             }
            }
        	cout<<"Nhap diem can tim: ";
        	cin>>diem_;	        
        	while(left<=right)
			{
	       		pivot= (left+right)/2;
		
	    	if(diem_< sv[pivot].diem) {
	            right=pivot-1;  
	    	}
	    	else if(diem_> sv[pivot].diem){
		    	left=pivot+1;
	    	}
	    	else
	         	if(diem_== sv[pivot].diem)
	        	{
	        		sv[pivot].stt = pivot+1;
					gotoxy(32,y+4);cout<<sv[pivot].stt;
	        		BangDataSV(x,y,dem+1);
		        	in1SV(sv[pivot]);
		        	dem++;
		        	break;
               	}
       		}
            if(!dem){
             	gotoxy(1,3);
	         	cout<<"sinh vien khong ton tai!";
         	}    
         	
			gotoxy(1,4);
			cout<<"An ESC de quay lai!";
			do
			{				
				c= getch();
			}while(c!=27);
			showMenuTimKiem();
			break;
		}
		default:{
			showMenuTimKiem();
			break;
		}
	}		
}

void PhanLoai()
{
	cout<<" ________________________________________________________________________________\n" ;
	cout<<"|          |  Xuat Sac   |     Gioi    |      Kha    |  Trung Binh |      Yeu    |\n";
	cout<<"| Ma Lop   |_____________|_____________|_____________|_____________|_____________|\n";
	cout<<"|          |  SL  |  %   |  SL  |  %   |  SL  |  %   |  SL  |  %   |  SL  |  %   |\n";
	cout<<"|__________|______|______|______|______|______|______|______|______|______|______|\n";
	int i=0;
	int p=1;
	int n;
	
	int XuatSac=0;
	int Gioi=0;
	int Kha=0;
	int TrungBinh=0;
	int Yeu=0;
	int SumXS=0,SumG=0,SumKha=0,SumTB=0,SumYeu=0,S=0;
	int a1=0,a2=0,a3=0,a4=0,a5=0;
	int b1=0,b2=0,b3=0,b4=0,b5=0;
	
	// Sap xep theo ma lop
	for (int i = demSV-1; i > 0; i--){
		for (int j = 0 ; j < i;j++){
			if (strcmp(sv[j].malop,sv[j+1].malop) > 0){
					swap(sv[j],sv[j+1]);
			}
		}
	}
	
	while(p<=demSV)
	{
		do
		{
		    if(sv[i].diem==10) XuatSac++;		       	
	       	if(sv[i].diem==9) Gioi++;		          
		    if(sv[i].diem>=6 &&sv[i].diem<=8) Kha++;		          
		    if(sv[i].diem>=4 &&sv[i].diem<=5) TrungBinh++;		           
		    if(sv[i].diem<=3) Yeu++;		            
		    i++;
		    p++;
		    n++;
		} while(strcmp(sv[i].malop,sv[i-1].malop)==0);
		SumXS += XuatSac;
		SumG += Gioi;
		SumKha += Kha;
		SumTB += TrungBinh;
		SumYeu += Yeu;
		S=SumXS+SumG+SumKha+SumTB+SumYeu;
		b1=((SumXS*100)/S);
		b2=((SumG*100)/S);
		b3=((SumKha*100)/S);
		b4=((SumTB*100)/S);
		b5=((SumYeu*100)/S);
		a1=((XuatSac*100)/n);
        a2=((Gioi*100)/n);
        a3=((Kha*100)/n);
        a4=((TrungBinh*100)/n);
        a5=((Yeu*100)/n);
        cout<<"| "<<setw(9)<<left<<sv[i-1].malop<<"|"<<" "<<setw(5)<<left<<XuatSac<<"|"<<" "<<setw(3)<<left<<a1<<"% "<<"|"<<" "<<setw(5)<<left<<Gioi<<"|"<<" "<<setw(3)<<left<<a2<<"% "
        <<"|"<<" "<<setw(5)<<left<<Kha<<"|"<<" "<<setw(3)<<left<<a3<<"% "<<"|"<<" "<<setw(5)<<left<<TrungBinh<<"|"<<" "<<setw(3)<<left<<a4<<"% "<<"|"<<" "<<setw(5)<<left<<Yeu<<"|"<<" "<<setw(3)<<left<<a5<<"% |"<<endl;
        cout<<"|__________|______|______|______|______|______|______|______|______|______|______|"<<endl;
        XuatSac=0;
	    Gioi=0;
	    Kha=0;
	    TrungBinh=0;
	    Yeu=0;
	    n=0;
	}
	    cout<<"| "<<setw(9)<<left<<"Tong"<<"|"<<" "<<setw(5)<<left<<SumXS<<"|"<<" "<<setw(3)<<left<<b1<<"% "<<"|"<<" "<<setw(5)<<left<<SumG<<"|"<<" "<<setw(3)<<left<<b2<<"% "
        <<"|"<<" "<<setw(5)<<left<<SumKha<<"|"<<" "<<setw(3)<<left<<b3<<"% "<<"|"<<" "<<setw(5)<<left<<SumTB<<"|"<<" "<<setw(3)<<left<<b4<<"% "<<"|"<<" "<<setw(5)<<left<<SumYeu<<"|"<<" "<<setw(3)<<left<<b5<<"% |"<<endl;
        cout<<"|__________|______|______|______|______|______|______|______|______|______|______|"<<endl;
}

void showMenuThongKe(){
	int t=ThietKeChayMuiTen(menuThongKe,3);
	switch(t){
		case 1:{
			system("cls"); Nocursortype();
        	int dem, n;
        	int temp ;
        	cout<<"_____________________BANG THONG KE________________________\n";
        	cout<<"__________________________________________________________\n";
        	cout<<"||     Ma lop    ||    Ten Lop    ||    So sinh vien    ||\n";
         	cout<<"**---------------**---------------**--------------------**\n";
        	for(int i=0;i<demSV;i++)
        	{//1 1 1 2 2 1 1 3 3 2 1
     		dem= 0;
	        	for(int j=0;j<demSV;j++)
	        	{
		    		temp = strcmp(sv[i].malop,sv[j].malop);
		    		if(temp==0)
		    		{
						if(i<=j){
							dem++;
						}
						else{
							break;
						}
					}
				}
	    		if(dem){						   	
					cout<<"||"<<setw(15)<<left<<sv[i].malop<<"||"<<setw(15)<<left<<sv[i].malop<<"||"<<setw(20)<<left<<dem<<"||"<<endl;
			     	cout<<"--------------------------------------------------------"<<endl;
			    	}
		    	}
			    	cout<<"||"<<setw(32)<<left<<"Tong "<<"||"<<setw(20)<<left<<demSV<<"||"<<endl;
			    	cout<<"__________________________________________________________"<<endl;
			    	gotoxy(65,2);
					cout<<"An ESC de quay lai!";
					do
					{				
						c= getch();
					}while(c!=27);
					showMenuThongKe();
					break;
		}
		case 2:{
					int n;
					system("cls");
					PhanLoai();
					gotoxy(85,2);
					cout<<"An ESC de quay lai!";
					do
					{				
						c= getch();
					}while(c!=27);
					showMenuThongKe();
					break;
			}
			default :{
					showMenuMain();
					break;
	        	}
        	}
}
int ThietKeChayMuiTen(stringMenu menuCanIn[],int n){
	// dat mang dinh xuat phat tai 1 va ket thuc tai n.
	// n: so phan tu cua string hay chinh la so lua chon
	int head=1;
	int tail=n;
	int dong=1;
	// in dong dau tien 
	inMauDong(dong-1,menuCanIn,n);
//	inSV();
	char c=' ';
	while(c!=13&&c!=77){
		c=getch();
		if(c==72){
			if(dong==head){
			dong=tail;
			}else dong--;
		}
		if(c==80){
			if(dong==tail){
			dong=head;
			}else dong++;
		}
		inMauDong(dong-1,menuCanIn,n);
//		inSV();	
	}
	return dong;
}
void inMauDong(int DongCanInMau,stringMenu menuCanIn[],int n){
	// xoa man hinh'
	system("cls");
	for(int i=0;i<DongCanInMau;i++)
		printf("%s",menuCanIn[i]);		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("%s",menuCanIn[DongCanInMau]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	
	for(int i=DongCanInMau+1;i<n;i++)
		if(i<n)
			printf("%s",menuCanIn[i]);
}
