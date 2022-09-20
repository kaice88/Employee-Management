#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/* HAM DOI MAU CHU */
void SET_COLOR(int color)
{
	WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void tieudechinh()
		{
			SET_COLOR(15);
			cout<<"                               +-----------------------------------------------------------------------------------------+\n";
			SET_COLOR(11);
			cout<<"                               '                                                                                         '\n";
			cout<<"                               '                                                                                         '\n";
			cout<<"                               '                         DE TAI:     QUAN LY NHAN VIEN                                   '\n";
			cout<<"                               '                         NHOM SV:    NGUYEN THI KIM CHI                                  '\n";
			cout<<"                               '                                     PHAM THI QUYNH LINH                                 '\n";
			cout<<"                               '                         GIANG VIEN: DO THI TUYET HOA                                    '\n";
			cout<<"                               '                                                                                         '\n";
            cout<<"                               '                                                                                         '\n";
			SET_COLOR(15);
			cout<<"                               +-----------------------------------------------------------------------------------------+\n";
		}
void Menu(){
    	{   cout<<endl;
		    SET_COLOR(15);
			cout<<"                                    +------------------------------------MENU-----------------------------------+"<<endl;
       	  	SET_COLOR(14);
			cout<<"                                    '   1.Nhap nhan vien                   |   2.In danh sach nhan vien         '"<<endl;
			SET_COLOR(15);
			cout<<"                                    '---------------------------------------------------------------------------'"<<endl;	 
			SET_COLOR(14);
			cout<<"                                    '   3.Bo sung nhan vien                |   4.Tim kiem nhan vien             '"<<endl;
			SET_COLOR(15);
			cout<<"                                    '---------------------------------------------------------------------------'"<<endl;
            SET_COLOR(14);
			cout<<"                                    '   5.Sap xep danh sach nhan vien      |   6.Xoa nhan vien                  '"<<endl;
			SET_COLOR(15);
			cout<<"                                    '---------------------------------------------------------------------------'"<<endl;
			SET_COLOR(14);
			cout<<"                                    '   7.Bo sung don vi                   |   8.Bo sung chuc vu                '"<<endl;
			SET_COLOR(15);
			cout<<"                                    '---------------------------------------------------------------------------'"<<endl;
			SET_COLOR(14);
			cout<<"                                    '   9.Thong ke                         |   10.Sua thong tin nhan vien       '"<<endl;
			SET_COLOR(15);
			cout<<"                                    +---------------------------------------------------------------------------+"<<endl;
			SET_COLOR(14);
			cout<<"                                    '   11.Ket thuc                        |   Lua chon chuc nang: ";
	        
		}

}
void Tieude(){
SET_COLOR(15);
cout<<"----------------------------------------------------------------------------------------"
<<"---------------------------------------------------------------------------------------------"<<endl;
SET_COLOR(14);
cout<<"|STT"<<"\t"<<"|"<<"MA NHAN VIEN"<<setw(5)<<"|"<<"HO VA TEN DEM"<<setw(5)<<"|"<<"TEN"<<setw(7)<<"|"<<"NGAY SINH"<<setw(6)<<"|"<<"GIOI TINH"
<<setw(3)<<"|"<<"DON VI"<<setw(7)<<"|"<<"CHUC VU"<<setw(8)<<"|"<<"NAM LAM VIEC"<<setw(4)<<"|"
<<"TRINH DO"<<setw(4)<<"|"<<"LUONG"<<setw(11)<<"|"<<"HE SO LUONG"<<setw(5)<<"|"<<"THUC LINH"<<endl;
SET_COLOR(15);
cout<<"----------------------------------------------------------------------------------------"
<<"---------------------------------------------------------------------------------------------"<<endl;
}

/*---------------------------------------------------------CAC HAM XU LY CHUOI------------------------------------------ */

/* HAM CAT KHOANG TRANG CUOI CHUOI 
 VD: trim("XU LY CHUOI          ") = "XU LY CHUOI" */
string trim(string str){
		string whitespace=" \t";
		const auto strBegin = str.find_first_not_of(whitespace);
		const auto strEnd = str.find_last_not_of(whitespace);
    	const auto strRange = strEnd - strBegin + 1;
		return str.substr(strBegin, strRange);
}
/* HAM LAY 4 SO CUOI CUA MA NHAN VIEN */
int tach(string str){
	str=str.substr(4,4);
	return stoi(str);
}
/* HAM DOI CHUOI IN HOA */
string ChuoiInHoa(string str){
	for(int i = 0 ; i < str.length(); i++ ){
		if( str[i] >= 'a' && str[i] <= 'z'){
			str[i]-=32;
		}
	}
return str;
}
/*-----------------------------------------------------------------------------------------------------------------------*/

/* HAM LAY NAM HIEN TAI */
int Namhientai(){
	int nCurYear;
	time_t Time = time(0);
	tm* Now = localtime(&Time);
	nCurYear = Now->tm_year + 1900;
	return nCurYear;
}

bool asc(string l, string r){
        return l.compare(r) < 0 ;
    };
bool desc(string l, string r){
        return l.compare(r) >0;
    };

class DS{
protected:
int n;
public:
virtual void docfile()=0;
virtual void ghifile()=0;
virtual int getsl() =0;
virtual string duyetma(int)=0;
};

/* CLASS NGAY SINH */
class Ngaysinh{
private:
	int Ngay;
	int Thang;
	int Nam;
public:
	int getNgay(){
		return Ngay;
	};
	void setNgay(int ngay){
		Ngay=ngay;
	};
	int getThang(){
		return Thang;
	};
	void setThang(int thang){
		Thang=thang;
	};
	int getNam(){
		return Nam;
	};
	void setNam(int nam){
		Nam=nam;
	};
};


/*  CLASS DON VI , DSDV  */
class Donvi{
protected:
string Ten;
string Ma;
public:
void Nhap(); // Nhap them 1 don vi
string getten(){return Ten;};
string getma() { return Ma;};
void setten( string ten){Ten=ten; };
void setma( string ma){ Ma=ma;} ;
void docfile(fstream &);//doc 1 don vi tu file DV.txt
void xuat();// Xuat 1 don vi
void ghifile(fstream &);
};

/* CLASS CHUC VU , DSCV  */
class Chucvu:public Donvi{
double Hs_phucap;
public:
void Nhap();
float geths() { return Hs_phucap;};
void setpc( double pc){ Hs_phucap=pc;} ;
void docfile(fstream &);
void ghifile(fstream &);
};

class DSDV:public DS{
 Donvi *dv;
 //int n;
 public:
 void docfile();
 void Nhap();// Nhap them nhieu don vi vao danh sach don vi
 void xuat();
 void ghifile();
 Donvi &operator [] (int i) const
 {
	  return dv[i];
 };
 int getsl(){
	return n;
};
string duyetma(int);
 
};


class DSCV:public DS{
 Chucvu *cv;
// int n;
 public:
 void docfile();
 void xuat();
 void Nhap();
 void ghifile();
 Chucvu &operator [] (int i) const
 {
	  return cv[i];
 };
 int getsl(){
	return n;
};
string duyetma(int);

};
/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// CLASS NHANVIEN ///////////////////////////////
class NhanVien{
	string MSNV;
	string HoTenDem;
	string Ten;
	Ngaysinh NgaySinh;
	string GioiTinh ;
	Donvi DonVi;
	Chucvu ChucVu;
	int NamLamViec;
	string TrinhDo;
    double HSLuong;
	public:
	void docfilenv(fstream &);
	void xuatnv(DSDV,DSCV);
	void nhapnv(DSDV, DSCV);
    void ghifilenv(fstream &);
	string getma(){ return MSNV;};
	string getten(){ return Ten;};
	string getgt(){ 
	string gt;
		 if(GioiTinh.compare("1")==0) gt="Nu";
			else gt="Nam";
		return gt;
	};
	string getmadv(){ return DonVi.getma();};
	string getmacv(){ return ChucVu.getma();};
    void setma(string ma){
        MSNV=ma;
    }
	void setho(string ho){
		HoTenDem=ho;
	}
	void setten(string ten){
		Ten=ten;
	}
	void setgioitinh(string gt){
		GioiTinh=gt;
	}
	void setdonvi(string dv){
		DonVi.setma(dv);
	}
	void setchucvu(string cv){
		ChucVu.setma(cv);
	}
	void setnamlv(int nam){
		NamLamViec=nam;
	}
	void settrinhdo(string td){
		TrinhDo=td;
	}
	void setngaysinh(int ngay, int thang , int nam){
		NgaySinh.setNgay(ngay);
		NgaySinh.setThang(thang);
		NgaySinh.setNam(nam);
	}
    int Thamnien();
	double gethsl();
	int TinhLuong();
	int TinhTL(DSCV);
	int Tinhtuoi();
	bool operator == (NhanVien);
  
};
class DSNV:public DS{
	NhanVien *nv;
	//int n;
	public:
	void docfile();
	void xuat(DSDV A,DSCV B);
	void timkiemten(string s,DSDV A,DSCV B);
	void timkiemma(string s,DSDV A,DSCV B);
    void Nhap(DSDV A, DSCV B);
	void them(int k,DSDV A, DSCV B);
	void themnv(DSDV A, DSCV B);
	void Xoama(string ma);
	void Xoaten(string ten);
	void Xoatuoi(int tuoi);
	int timvt(NhanVien x);
	void Sapxep(bool(*func_ptr)(string,string));
	bool DSTang();
	bool DSGiam();
	void ghifile();
    void SuaThongTin(string ma,DSDV A,DSCV B);
	int getsl(){
		return n;
	}
	string duyetma(int);
	int slnam(string);
	int slnu(string);
	int tongtl(string, DSCV);
	void Thongke(DSDV,DSCV);
	
   
};
/*-----------------------------------------------------------------------------------------------------*/
/* CAC HAM XU LY DON VI */
void Donvi::docfile(fstream &f2){
    string s;
    getline(f2,Ma,' ');
	getline(f2,s,'|');
	getline(f2,Ten);
}
void DSDV::docfile(){
	fstream f2;
	f2.open("DV.txt",ios_base::in);
	int dem=0;
	while (f2.eof() == false)
	{
		string x;
		getline(f2, x); 
		dem++;
		
	}
	n=dem;
	dv = new Donvi[n];
	f2.close();
	f2.open("DV.txt",ios_base::in);
	f2.ignore();
	f2.ignore();
	f2.ignore();
	for ( int i = 0 ; i < n ; i ++){
		dv[i].docfile(f2);
	}
	f2.close();
}
string DSDV::duyetma(int k){
        int max = stoi(dv[0].getma());
        for(int i = 1 ; i < k ; i++){
            if (max < stoi(dv[i].getma()))
            max = stoi(dv[i].getma());
        }
        string str = to_string(max+1);
        int len = str.length();
        for(int i = 1 ; i <= 2-len;i++)
        {
         str = str.insert(0,"0");
        }
	return str;
    };
void Donvi::xuat(){
SET_COLOR(15);
cout<<"                                                            "<<Ma<<setw(15-Ma.length())<<"|"<<Ten<<endl;
}
void DSDV::xuat(){
cout<<endl;
SET_COLOR(15);
cout<<"                                                            ---------------------------"<<endl;
SET_COLOR(14);
cout<<"                                                            "<<"|MA DON VI"<<setw(5)<<"|"<<"TEN DON VI"<<endl;
SET_COLOR(15);
cout<<"                                                            ---------------------------"<<endl;
for(int i = 0; i < n; i++)
		{
		  dv[i].xuat();
		}
cout<<endl;
}
void Donvi::ghifile(fstream &f2){
	f2<<endl;
	f2<<getma()<<setw(8)<<"|"<<getten();
}
void Chucvu::ghifile(fstream &f2){
    Donvi::ghifile(f2);
    f2<<setw(20-getten().length())<<"|"<<geths();
}
void DSDV::ghifile(){
	fstream f2;
	f2.open("DV.txt",ios_base::out);
	for( int i =0 ; i < n ; i++){
		if(i==n-1)
		{
			dv[i].ghifile(f2);
		}
		else {
			dv[i].ghifile(f2);
			f2<<endl;
		}
	}
	f2.close();
}
void Donvi::Nhap(){
	SET_COLOR(15);
	cout<<"                                    - Ten don vi: "; SET_COLOR(15);getline(cin,Ten);
	Ten = ChuoiInHoa(Ten);
}
void DSDV::Nhap(){
	fstream f2;
	f2.open("DV.txt",ios_base::app);
	int sl;
	string str;
	cout<<endl;
	SET_COLOR(14);
	cout<<"                                    Nhap so luong don vi: "; SET_COLOR(15);cin >> sl;
	 int slmoi=n+sl;
	Donvi *dvmoi = new Donvi[slmoi];
	for(int i =0 ; i < n ; i ++){
		dvmoi[i]=dv[i];
	}
	delete [] dv;
	dv=dvmoi;
	n=slmoi;
	int d=1;
    int dem=0;
	for(int i=n-sl; i<n; i++){
		cout<<endl;
		SET_COLOR(14);
        cout<<"                                    Nhap don vi thu "<<d++<<":"<<endl;
        if(i==n-sl) cin.ignore();
        dv[i].Nhap();
        	for(int j = 0 ; j < i ; j++){
		if ( dv[i].getten().compare(dv[j].getten())==0)
		{
			dem = 1;
		}
		}
        if(dem==1)
		{
			do
			{
			SET_COLOR(11);
			cout<<"                                    !  Trung ten don vi  !"<<endl;
			cout<<"                                    !  Moi ban nhap lai  !"<<endl;
			dv[i].Nhap();
			dem = 0 ;
			for(int j = 0 ; j < i ; j++){
			if ( dv[i].getten().compare(dv[j].getten())==0)
				{
				dem = 1;
				}
			}
			}
			while(dem==1);
		}
		str = duyetma(i);
        dv[i].setma(str);
		dv[i].ghifile(f2);
    }
	
	f2.close();
}
/*----------------------------------------------------------------------------------------------------------*/


/* CAC HAM XU LY CHUC VU */
void Chucvu::docfile(fstream &f3){
    string s;
    getline(f3,Ma,' ');
	getline(f3,s,'|');
	getline(f3,Ten,'|');
	f3 >> Hs_phucap;
	f3.ignore();
	Ten=trim(Ten);
}
void DSCV::docfile(){
	fstream f3;
	f3.open("CV.txt",ios_base::in);
	int dem=0;
	while (f3.eof() == false)
	{
		string x;
		getline(f3, x);
		dem++;
		
	}
	n=dem;
	cv = new Chucvu[n];
	f3.close();
	f3.open("CV.txt",ios_base::in);
	f3.ignore();
	f3.ignore();
	f3.ignore();
	for ( int i = 0 ; i < n ; i ++){
		cv[i].docfile(f3);
	}
	f3.close();
}
string DSCV::duyetma(int k){
        int max = stoi(cv[0].getma());
        for(int i = 1 ; i < k ; i++){
            if (max < stoi(cv[i].getma()))
            max = stoi(cv[i].getma());
        }
        string str = to_string(max+1);
	return str;
}
void DSCV::xuat(){
cout<<endl;
SET_COLOR(15);
cout<<"                                                            ---------------------------"<<endl;
SET_COLOR(14);
cout<<"                                                            "<<"|MA CHUC VU"<<setw(4)<<"|"<<"TEN CHUC VU"<<endl;
SET_COLOR(15);
cout<<"                                                            ---------------------------"<<endl;
for(int i = 0; i < n; i++)
		{
		  SET_COLOR(14);
		  cv[i].xuat();
		}
cout<<endl;
		
}


void DSCV::ghifile(){
	fstream f2;
	f2.open("CV.txt",ios_base::out);
	for( int i =0 ; i < n ; i++){
		if(i==n-1)
		{
			cv[i].ghifile(f2);
		}
		else {
			cv[i].ghifile(f2);
			f2<<endl;
		}
	}
	f2.close();
}
void Chucvu::Nhap(){
	SET_COLOR(15);
	cout<<"                                    - Ten chuc vu: ";SET_COLOR(15); getline(cin,Ten);
	Ten = ChuoiInHoa(Ten);
	SET_COLOR(15);
	cout<<"                                    - He so phu cap: "; SET_COLOR(15);cin >> Hs_phucap;
	cin.ignore();
}
void DSCV::Nhap(){
	fstream f2;
	f2.open("CV.txt",ios_base::app);
	int sl;
	string str;
	cout<<endl;
	SET_COLOR(14);
	cout<<"                                    Nhap so luong chuc vu: ";SET_COLOR(15); cin >> sl;
	 int slmoi=n+sl;
	Chucvu *cvmoi = new Chucvu[slmoi];
	for(int i =0 ; i < n ; i ++){
		cvmoi[i]=cv[i];
	}
	delete [] cv;
	cv=cvmoi;
	n=slmoi;
	int d=1;
	int dem=0;
	for(int i=n-sl; i<n; i++){
		cout<<endl;
		SET_COLOR(14);
        cout<<"                                    Nhap chuc vu thu "<<d++<<":"<<endl;
       if(i==n-sl) cin.ignore();
        cv[i].Nhap();
		for(int j = 0 ; j < i ; j++){
		if ( cv[i].getten().compare(cv[j].getten())==0)
		{
			dem = 1;
		}
		}
		if(dem==1)
		{
			do
			{
			SET_COLOR(11);
			cout<<"                                    ! Trung ten chuc vu  !"<<endl;
			cout<<"                                    !  Moi ban nhap lai  !"<<endl;
			cv[i].Nhap();
			dem = 0 ;
			for(int j = 0 ; j < i ; j++){
			if ( cv[i].getten().compare(cv[j].getten())==0)
				{
				dem = 1;
				}
			}
			}
			while(dem==1);
		}
		str = duyetma(i);
        cv[i].setma(str);
		cv[i].ghifile(f2);
    }
	//ghifile();
	f2.close();
}
/*----------------------------------------------------------------------------------------------------------*/


/* CAC HAM XU LY NHAN VIEN */
int NhanVien::Thamnien(){
        return Namhientai() - NamLamViec;
    }
double NhanVien::gethsl(){
        HSLuong = (Thamnien()>=8) ? 4.5 : ((Thamnien()>=5) ? 4 : ((Thamnien()>=3) ? 3.5: 3));
        return HSLuong;
    }
int NhanVien::TinhLuong(){
      return gethsl()*15*100000;
   }
int NhanVien::TinhTL(DSCV B){
        for(int j = 0 ; j < B.getsl(); j++ )
	    {
		if (B[j].getma().compare(ChucVu.getma())==0)
		ChucVu.setpc(B[j].geths());
	    }
        return TinhLuong()+TinhLuong()*ChucVu.geths();
    }
int NhanVien::Tinhtuoi(){
		return Namhientai() - NgaySinh.getNam();
	}
bool NhanVien::operator == (NhanVien obj){
		if ((HoTenDem.compare(obj.HoTenDem)==0) && (Ten.compare(obj.Ten)==0) &&(GioiTinh.compare(obj.GioiTinh)==0) &&
		(NgaySinh.getNam()==obj.NgaySinh.getNam()) && (NgaySinh.getNgay()==obj.NgaySinh.getNgay()) && (NgaySinh.getThang()==obj.NgaySinh.getThang())
		&& (DonVi.getma().compare(obj.DonVi.getma())==0) && (ChucVu.getma().compare(obj.ChucVu.getma())==0)
		)
		 return true;
		 else return false;
	}
string DSNV::duyetma(int k){
        int max = tach(nv[0].getma());
        for(int i = 1 ; i < k ; i++){
            if (max < tach(nv[i].getma()))
            max = tach(nv[i].getma());
        }
        string str = to_string(max+1);
        int len = str.length();
        for(int i = 1 ; i <= 4-len;i++)
        {
         str = str.insert(0,"0");
        }
	return str;
    };
    
int DSNV::slnam(string Ma){
		int d=0;
		for(int i = 0 ; i < n ; i++){
			if( (nv[i].getmadv().compare(Ma)==0) && (nv[i].getgt().compare("Nam")==0)) 
				d=d+1;
		}
		return d;
	};
int DSNV::slnu(string Ma){
	int d=0;
		for(int i = 0 ; i < n ; i++){
			if( (nv[i].getmadv().compare(Ma)==0) && (nv[i].getgt().compare("Nu")==0) )
				d=d+1;
		}
		return d;
	};
int DSNV::tongtl(string Ma,DSCV B){
		int s=0;
		for(int i = 0 ; i < n ; i++){
			if( (nv[i].getmadv().compare(Ma)==0)) 
				s=s+nv[i].TinhTL(B);
		}
		return s;
	};
void DSNV::Thongke(DSDV A,DSCV B){
		cout<<endl;
		SET_COLOR(15);
		cout<<"                                           +----------------------BANG THONG KE--------------------------+"<<endl;
		SET_COLOR(14);
		cout<<"                                           "<<"DON VI"<<setw(7)<<"|"<<"NHAN VIEN NU"<<setw(5)<<"|"<<"NHAN VIEN NAM"<<setw(5)<<"|"<<"TONG THUC LINH"<<endl;
		SET_COLOR(15);
		cout<<"                                           +-------------------------------------------------------------+"<<endl;
		for(int i = 0 ; i < A.getsl(); i++){
		SET_COLOR(15);
		cout<<"                                           "<<A[i].getten()<<setw(13-A[i].getten().length())<<"|"<<slnu(A[i].getma())<<setw(16)<<"|"<<slnam(A[i].getma())<<setw(17)<<"|"<<tongtl(A[i].getma(),B)<<endl;
		}
	}
void NhanVien::docfilenv(fstream &f1)
{		string s;
		getline(f1,MSNV,' ');
		getline(f1,s,'|');
		getline(f1,HoTenDem,'|');
		getline(f1,Ten,' ');
		getline(f1,s,'|');
		int ngay;
		f1 >> ngay;
		NgaySinh.setNgay(ngay);
		f1.ignore();
		int thang;
		f1 >> thang;
		NgaySinh.setThang(thang);
		f1.ignore();
		int nam;
		f1 >> nam;
		NgaySinh.setNam(nam);
		getline(f1,s,'|');
		getline(f1,GioiTinh,' ');
		getline(f1,s,'|');
		string ma1;
		getline(f1,ma1,' ');	
		DonVi.setma(ma1);
		getline(f1,s,'|');
		string ma2;
		getline(f1,ma2,' ');	
		ChucVu.setma(ma2);
		getline(f1,s,'|');
		f1 >> NamLamViec;
		getline(f1,s,'|');
		getline(f1,TrinhDo);
		HoTenDem=trim(HoTenDem);
}
void DSNV::docfile(){
	fstream f1;
	f1.open("NV.txt",ios_base::in);
	int dem=0;
	while (f1.eof() == false)
	{
		string x;
		getline(f1, x); 
		dem++;
		
	}
	n=dem;
	nv = new NhanVien[n];
	f1.close();
	f1.open("NV.txt",ios_base::in);
	for ( int i = 0 ; i < n ; i ++){
		nv[i].docfilenv(f1);
	}
	f1.close();
}
void NhanVien::xuatnv(DSDV A,DSCV B){
	for(int i = 0 ; i < A.getsl(); i++ )
	{
		if (A[i].getma().compare(DonVi.getma())==0)
		DonVi.setten(A[i].getten());
	}
	for(int j = 0 ; j < B.getsl(); j++ )
	{
		if (B[j].getma().compare(ChucVu.getma())==0)
		ChucVu.setten(B[j].getten());
	}
    SET_COLOR(15);
	cout<<"\t"<<"|"<<MSNV<<setw(9)<<"|"<<HoTenDem<<setw(18-HoTenDem.length())<<"|"<<Ten<<setw(10-Ten.length())<<"|"<<setw(2)<<NgaySinh.getNgay()<<"/"<<setw(2)<<NgaySinh.getThang()<<"/"<<NgaySinh.getNam()
	<<setw(5)<<"|"<<getgt()<<setw(12-getgt().length())<<"|"<<DonVi.getten()
	<<setw(13-DonVi.getten().length())<<"|"<<ChucVu.getten()<<setw(15-ChucVu.getten().length())<<"|"<<NamLamViec<<setw(12)<<"|"<<TrinhDo<<setw(12-TrinhDo.length())<<"|"<<to_string(TinhLuong())<<"\t"<<"|"<<HSLuong<<"\t\t"<<"|"<<to_string(TinhTL(B))<<endl;
}

void DSNV::xuat(DSDV A,DSCV B){
	Tieude();
	for(int i = 0; i < n; i++)
		{
	      cout<<"|"<<i+1;
		  nv[i].xuatnv(A,B);
		}
}
void NhanVien::nhapnv(DSDV A, DSCV B){
	SET_COLOR(15);
    cout<<"                                    - Ho Va Ten dem: "; getline(cin,HoTenDem);
	HoTenDem = ChuoiInHoa(HoTenDem);
    cout<<"                                    - Ten: "; getline(cin,Ten);
	Ten = ChuoiInHoa(Ten);
    cout<<"                                    - Ngay sinh: "<<endl; 
    int ngay;
    cout<<"                                    - Ngay: ";cin >> ngay;
    NgaySinh.setNgay(ngay);
    int thang;
    cout<<"                                    - Thang: ";cin >> thang;
    NgaySinh.setThang(thang);
    int nam;
    cout<<"                                    - Nam: ";cin >> nam;
    NgaySinh.setNam(nam);
	cin.ignore();
    cout<<"                                    - Gioi tinh (Nu-1 / Nam-0): ";getline(cin,GioiTinh);
    cout<<"                                    - Don vi: ";
    string dv; getline(cin,dv);
	int dem1 = 0;
	for(int i = 0 ; i < A.getsl(); i++){
		if ( dv.compare(A[i].getma())==0)
		{
			dem1 = 1;
		}
	}
		if(dem1==0)
		{
			do
			{
			SET_COLOR(11);
			cout<<"                                    ! Ma don vi khong hop le  !"<<endl;
			cout<<"                                      !  Moi ban nhap lai  !"<<endl;
			SET_COLOR(15);
			cout<<"                                    - Don vi: ";
			getline(cin,dv);
			for(int i = 0 ; i < A.getsl(); i++){
			if (dv.compare(A[i].getma())==0 )
				{
				dem1 = 1;
				}
			}
			}
			while(dem1==0);
		}
    DonVi.setma(dv);
	SET_COLOR(15);
    cout<<"                                    - Chuc vu : ";
    string cv; getline(cin,cv);
	int dem2 = 0;
	for(int i = 0 ; i < B.getsl(); i++){
		if ( cv.compare(B[i].getma())==0)
		{
			dem2 = 1;
		}
	}
		if(dem2==0)
		{
			do
			{
			SET_COLOR(11);
			cout<<"                                    ! Ma chuc vu khong hop le  !"<<endl;
			cout<<"                                      !  Moi ban nhap lai  !"<<endl;
			SET_COLOR(15);
		    cout<<"                                    - Chuc vu : ";
			getline(cin,cv);
			for(int i = 0 ; i < B.getsl(); i++){
			if (cv.compare(B[i].getma())==0 )
				{
				dem2 = 1;
				}
			}
			}
			while(dem2==0);
		}
    ChucVu.setma(cv);
	SET_COLOR(15);
	cout<<"                                    - Nam lam viec: "; cin >>NamLamViec ;
	cin.ignore();
	cout<<"                                    - Trinh do: ";getline(cin,TrinhDo);
	TrinhDo = ChuoiInHoa(TrinhDo);
	MSNV.clear();
	MSNV=MSNV.append(DonVi.getma()).append(ChucVu.getma());
}
void NhanVien::ghifilenv(fstream &f1){
	f1<<MSNV<<setw(8)<<"|"<<HoTenDem<<setw(18-HoTenDem.length())<<"|"<<Ten<<setw(10-Ten.length())<<"|"<<setw(2)<<NgaySinh.getNgay()<<"/"<<setw(2)<<NgaySinh.getThang()<<"/"<<NgaySinh.getNam()
	<<setw(5)<<"|"<<GioiTinh<<setw(12-GioiTinh.length())<<"|"<<DonVi.getma()
	<<setw(7)<<"|"<<ChucVu.getma()<<setw(7)<<"|"<<NamLamViec<<setw(8)<<"|"<<TrinhDo;

}
void DSNV::ghifile(){
	fstream f1;
	f1.open("NV.txt",ios_base::out);
	for( int i =0 ; i < n ; i++){
		if(i==n-1)
		{
			nv[i].ghifilenv(f1);
		}
		else {
			nv[i].ghifilenv(f1);
			f1<<endl;
		}
			
	}
	f1.close();
}
void DSNV::Nhap(DSDV A, DSCV B){
	string str ;
	int sl;
	cout<<endl;
	SET_COLOR(14);
	cout<<"                                    Nhap so luong nhan vien: ";SET_COLOR(15);cin >> sl;
    int slmoi=n+sl;
	NhanVien *nvmoi = new NhanVien[slmoi];
	for(int i =0 ; i < n ; i ++){
		nvmoi[i]=nv[i];
	}
	delete [] nv;
	nv=nvmoi;
	n=slmoi;
	int d=1;
	int dem=0;
	for(int i=n-sl; i<n; i++){
		cout<<endl;
		SET_COLOR(14);
        cout<<"                                    Nhap nhan vien thu "<<d++<<":"<<endl;
        if(i==n-sl) cin.ignore();
        nv[i].nhapnv(A,B);
		for(int j = 0 ; j < i ; j++){
		if ( nv[i] == nv[j])
		{
			dem = 1;
		}
		}
		if(dem==1)
		{
			do
			{
			SET_COLOR(11);
			cout<<"                                    ! Nhan vien nay da co trong danh sach !"<<endl;
			cout<<"                                           !  Moi ban nhap lai  !"<<endl;
			cout<<endl;
			nv[i].nhapnv(A,B);
			dem = 0 ;
			for(int j = 0 ; j < i ; j++){
			if ( nv[i]== nv[j])
				{
				dem = 1;
				}
			}
			}
			while(dem==1);
		}
		str = duyetma(i);
        nv[i].setma(nv[i].getma().append(str));
    }
	ghifile();

}
void DSNV::them(int k,DSDV A, DSCV B){
    fstream f1;
	f1.open("NV.txt",ios_base::app);
    string str = duyetma(n);
	NhanVien nv1;
	SET_COLOR(14);
	cout<<"                                    Nhap nhan vien can them: "<<endl;
	nv1.nhapnv( A, B);
	NhanVien *nvmoi = new NhanVien[n+1];
	for(int i =0 ; i < n ; i ++){
		nvmoi[i]=nv[i];
	}
	delete [] nv;
	nv=nvmoi;
	n=n+1;
	for(int i = n-1; i > k ; i--)
    {
        nvmoi[i]=nv[i-1];
    }
    nv[k]=nv1;
	nv[k].setma(nv[k].getma().append(str));
  
   ghifile();
    f1.close();
}

int DSNV::timvt(NhanVien x){
	if(DSTang())
	{
		if(x.getten().compare(nv[0].getten()) <0) {
		return 0;
		}
		if(x.getten().compare(nv[n-1].getten()) >0) {
		return n;
		}
		int i;
		for(i = 0; i < n; i++) {
			if(x.getten().compare(nv[i].getten()) <= 0) {
			return i;
			}
		}
	}
	else if(DSGiam())
	{
		if(x.getten().compare(nv[0].getten()) > 0) {
		return 0;
		}
		if(x.getten().compare(nv[n-1].getten()) < 0) {
		return n;
		}
		int i;
		for(i = 0; i < n; i++) {
			if(x.getten().compare(nv[i].getten()) >= 0) {
			return i;
			}
		}
	}
	else 
	{
		Sapxep(asc);
		return timvt(x);
	}	
	}
void DSNV::themnv(DSDV A, DSCV B){
    fstream f1;
	f1.open("NV.txt",ios_base::app);
    string str = duyetma(n);
	NhanVien nv1;
	SET_COLOR(14);
	cout<<"                                    Nhap nhan vien can them: "<<endl;
	nv1.nhapnv( A, B);
	int vt=timvt(nv1);
	NhanVien *nvmoi = new NhanVien[n+1];
	for(int i =0 ; i < n ; i ++){
		nvmoi[i]=nv[i];
	}
	delete [] nv;
	nv=nvmoi;
	n=n+1;
	for(int i = n-1; i > vt ; i--)
    {
        nvmoi[i]=nv[i-1];
    }
    nv[vt]=nv1;
	nv[vt].setma(nv[vt].getma().append(str));
   ghifile();
    f1.close();
}
void swap(NhanVien &nv1, NhanVien &nv2){
	NhanVien temp = nv1;
    nv1 = nv2;
    nv2 = temp;
}
void DSNV::Sapxep(bool(*func_ptr)(string,string)){
    int i, j;
	for(i = 0; i < n - 1; i++) {
		for(j = n - 1; j > i; j --) {
			if((*func_ptr)(nv[j].getten(),nv[j-1].getten())) {
				swap(nv[j],nv[j-1]);
			}
		}
	}
	ghifile();
}
bool DSNV::DSTang(){
 	for(int i = 0; i < n-1; i++){
        if(nv[i].getten().compare(nv[i+1].getten()) > 0) return false;
    }
    return true;
}
bool DSNV::DSGiam(){
	for(int i = 0; i < n-1; i++){
        if(nv[i].getten().compare(nv[i+1].getten()) < 0) return false;
    }
    return true;
}
void DSNV::Xoama(string ma){
    int i, j;
	int d = 0;
    char lc;
	for(i=0; i<n; i++) {
		if(nv[i].getma().compare(ma)==0)
		 {  
             ++d;
            if(d==1) 
            {
                cout<<"                                                  Ban co thuc su muon xoa khong ?(C/K):"; cin>>lc;
                lc = toupper(lc);
                if(lc=='C') 
                for(j=i; j<n-1; j++) 
                    {
			            nv[j] = nv[j+1];
		            }  
                else break;   
            }
            else {
                for(j=i; j<n-1; j++) 
                {
			        nv[j] = nv[j+1];
		        }   
            }   
		n--;
		i--;
		}	
	}
	SET_COLOR(11);
	if (d==0) cout<<"                                                  => Khong co nhan vien nao"<<endl;
	ghifile();
}
void DSNV::Xoaten(string ten){
    int i, j;
	int d = 0;
    char lc;
	for(i=0; i<n; i++) {
		if(nv[i].getten().compare(ten)==0) {
            ++d;
			if(d==1) 
                {
                SET_COLOR(11);
                cout<<"                                                  Ban co thuc su muon xoa khong ?(C/K):"; cin >>lc;
                lc = toupper(lc);
                if(lc=='C') 
                for(j=i; j<n-1; j++) 
                    {
			         nv[j] = nv[j+1];
		            }
                else break;    
                }
            else {
                for(j=i; j<n-1; j++) 
                    {
			         nv[j] = nv[j+1];
		            }
                }        
		n--;
		i--;
		}
	}
	SET_COLOR(11);
	if (d==0) cout<<"                                                  => Khong co nhan vien nao"<<endl;
	ghifile();
}
void DSNV::Xoatuoi(int tuoi){
    int i, j;
	int d=0;
    char lc;
	for(i=0; i<n; i++) {
		if(nv[i].Tinhtuoi() >= tuoi){
			 ++d;
			if(d==1) 
                {
                SET_COLOR(11);
                cout<<"                                                  Ban co thuc su muon xoa khong ?(C/K):"; cin >>lc;
                lc = toupper(lc);
                if(lc=='C') 
                for(j=i; j<n-1; j++) 
                    {
			         nv[j] = nv[j+1];
		            }
                else break;    
                }
            else {
                for(j=i; j<n-1; j++) 
                    {
			         nv[j] = nv[j+1];
		            }
                }     
		n--;
		i--;
		}
	}
	SET_COLOR(11);
	if (d==0) cout<<"                                                  => Khong co nhan vien nao"<<endl;
	ghifile();
}

void DSNV::SuaThongTin(string ma,DSDV A,DSCV B){
int d=0;
int vt;
string s;
int n;
int lc1;
char lc2;
string dv,cv;
int dem1 = 0;
int dem2 = 0;
string str ; 	
for(int i = 0; i < DSNV::n; i++)
		{
			if(nv[i].getma().compare(ma)==0)
			{   
				d=1;
                vt=i;
			}
		}
    	
    if (d==0) {
	SET_COLOR(11);
	cout<<"                                                   => Khong co nhan vien nao    "<<endl;
	}
    if (d==1){
	Tieude();
    cout<<"|"<<"1";
	nv[vt].xuatnv(A,B);
	do {
		cout<<endl;
		SET_COLOR(15);
		cout<<"                                                +------------------------------------------------+"<<endl;
       	SET_COLOR(14);
		cout<<"                                                '   1.Ho va Ten dem       |   2.Ten              '"<<endl;
		SET_COLOR(15);
		cout<<"                                                '------------------------------------------------'"<<endl;	
		SET_COLOR(14);
		cout<<"                                                '   3.Ngay sinh           |   4.Gioi tinh        '"<<endl;
		SET_COLOR(15);
		cout<<"                                                '------------------------------------------------'"<<endl;
		SET_COLOR(14);
		cout<<"                                                '   5.Don vi              |   6.Chuc vu          '"<<endl;
		SET_COLOR(15);
		cout<<"                                                '------------------------------------------------'"<<endl;
        SET_COLOR(14);
		cout<<"                                                '   7.Nam lam viec        |   8.Trinh do hoc van '"<<endl;
		SET_COLOR(15);
		cout<<"                                                +------------------------------------------------'"<<endl;
		cout<<"                                                ( Nhan 0 de quay lai Menu )"<<endl;
		SET_COLOR(14);
		cout<<"                                                Lua chon: "; cin>>lc1;
		switch(lc1){
			case 1:
			SET_COLOR(15);
			cout<<"                                                - Ho Va Ten dem: "; cin.ignore();
			getline(cin,s); s = ChuoiInHoa(s);
			nv[vt].setho(s);
			break;
			case 2:
			SET_COLOR(15);
			cout<<"                                                - Ten: "; cin.ignore();
			getline(cin,s);s = ChuoiInHoa(s);
			nv[vt].setten(s);
			break;
			case 3:
			SET_COLOR(15);
			cout<<"                                                - Ngay sinh: "<<endl; 
            int ngay;
            SET_COLOR(15);
			cout<<"                                                - Ngay: ";cin >> ngay;
            int thang;
            SET_COLOR(15);
			cout<<"                                                - Thang: ";cin >> thang;
            int nam;
            SET_COLOR(15);
			cout<<"                                                - Nam: ";cin >> nam;
            nv[vt].setngaysinh(ngay,thang,nam);
			break;
			case 4:
			SET_COLOR(15);
			cout<<"                                                - Gioi tinh (Nu-1 / Nam-0): ";cin.ignore();
			getline(cin,s);
			nv[vt].setgioitinh(s);
			break;
			case 5:
            A.xuat();
			SET_COLOR(15);
			cout<<"                                                - Don vi: ";cin.ignore();
			getline(cin,dv);
			for(int i = 0 ; i < A.getsl(); i++){
				if ( dv.compare(A[i].getma())==0)
					{
						dem1 = 1;
					}
			}
			if(dem1==0)
			{
				do
					{
						SET_COLOR(11);
						cout<<"                                                ! Ma don vi khong hop le  !"<<endl;
						cout<<"                                                   !  Moi ban nhap lai  !"<<endl;
					    SET_COLOR(15);
						cout<<"                                                - Don vi: ";
						getline(cin,dv);
						for(int i = 0 ; i < A.getsl(); i++){
						if (dv.compare(A[i].getma())==0 )
						{
							dem1 = 1;
						}
						}
					}
			while(dem1==0);
			}
			nv[vt].setdonvi(dv);
			break;
			case 6:
            B.xuat();
			SET_COLOR(15);
       		cout<<"                                                - Chuc vu : ";cin.ignore();
			    getline(cin,cv);
			for(int i = 0 ; i < B.getsl(); i++){
				if ( cv.compare(B[i].getma())==0)
					{
						dem2 = 1;
					}
			}
			if(dem2==0)
			{
				do
					{
						SET_COLOR(11);
						cout<<"                                                ! Ma chuc vu khong hop le  !"<<endl;
						cout<<"                                                   !  Moi ban nhap lai  !"<<endl;
						SET_COLOR(15);
		   				cout<<"                                                - Chuc vu : ";
						getline(cin,cv);
						for(int i = 0 ; i < B.getsl(); i++){
						if (cv.compare(B[i].getma())==0 )
						{
							dem2 = 1;
						}
						}
					}
			while(dem2==0);
			}
   			nv[vt].setchucvu(cv);
			break;
			case 7:
			SET_COLOR(15);
			cout<<"                                                - Nam lam viec: "; cin >> n ;
			nv[vt].setnamlv(n);
			break;
			case 8:
			SET_COLOR(15);
		    cout<<"                                                - Trinh do: ";cin.ignore();
			getline(cin,s);s = ChuoiInHoa(s);
			nv[vt].settrinhdo(s);
			break ;
			case 0: 
			break;
		}
        str= nv[vt].getma().substr(4,4);
        nv[vt].setma(nv[vt].getmadv().append(nv[vt].getmacv()).append(str));
		Tieude();
        cout<<"|"<<"1";
	    nv[vt].xuatnv(A,B);
	SET_COLOR(14);
	cout<<"                                                Ban co muon tiep tuc ? (C/K): "; SET_COLOR(15);cin >> lc2;
	lc2 = toupper(lc2);
	}
	while (lc2=='C');
	} 	
	ghifile();
}


void DSNV::timkiemma(string s,DSDV A,DSCV B){
		int d=0;
        int k=0;
		for(int i = 0; i < n; i++)
		{
			if(nv[i].getma().compare(s)==0)
			{   ++d;
				if(d==1) Tieude();
				SET_COLOR(15);
                cout<<"|"<<++k;
				nv[i].xuatnv(A,B);
			}
		}	
		SET_COLOR(11);
		if (d==0) cout<<"                                                  => Khong co nhan vien nao"<<endl;
       
}
void DSNV::timkiemten(string s,DSDV A,DSCV B){
		int d=0;
        int k=0;
		for(int i = 0; i < n; i++)
		{
			if(nv[i].getten().compare(s)==0)
			{   ++d;
				if(d==1) Tieude();
				SET_COLOR(15);
                cout<<"|"<<++k;
				nv[i].xuatnv(A,B);
			}
		}
		SET_COLOR(11);	
		if (d==0) cout<<"                                                  => Khong co nhan vien nao"<<endl;
       
}
/*----------------------------------------------------------------------------------------------------------*/

/* HAM MAIN */
int main(){
    tieudechinh();
	DSNV ds1;
    DSDV ds2;
	DSCV ds3;
	ds1.docfile();
	ds2.docfile();
	ds3.docfile();
	string luachon;
    int n,n2,n3,n4,n5,n6,n7,n8,n9;
    string s1,s2,s3,s4,s5;

    do
    {
        Menu();
		cin >> n;
        switch(n)
        {	
			case 1:
				ds2.xuat();
				ds3.xuat();
				ds1.Nhap(ds2,ds3);
				break;
            case 2:
                ds1.xuat(ds2,ds3);
                break;
            case 3:
				cout<<endl;
				SET_COLOR(15);
		     	cout<<"                                                  +------------------------------------------------+"<<endl;
				SET_COLOR(14);
                cout<<"                                                  '  1.Them vao dau danh sach                      '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  '------------------------------------------------'"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  2.Them vao cuoi danh sach                     '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  '------------------------------------------------'"<<endl;
				SET_COLOR(14);
				cout<<"                                                  '  3.Them vao vi tri bat ki                      '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  '------------------------------------------------'"<<endl;
				SET_COLOR(14);
				cout<<"                                                  '  4.Them nhan vien vao danh sach da sap xep     '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  +------------------------------------------------+"<<endl;
	            SET_COLOR(14);
				cout<<"                                                  ( Nhan 0 de quay lai Menu )"<<endl;
                cout<<"                                                  Lua chon: ";cin >> n2;
                cin.ignore();
				ds2.xuat();
				ds3.xuat();
                if(n2==1) ds1.them(0,ds2,ds3);
                if(n2==2) ds1.them(ds1.getsl(),ds2,ds3);
				if(n2==3) {
					SET_COLOR(14);
					cout<<"                                                  Nhap vi tri can them: ";
					cin>>n5;
					cin.ignore();
                	ds1.them(n5-1,ds2,ds3);
				}
				if(n2==4){
					ds1.themnv(ds2,ds3);
				}
				if(n2==0) break;
                break;
            case 4:
				cout<<endl;
				SET_COLOR(15);
				cout<<"                                                  +------------------------------------------------+"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  1.Tim theo ma nhan vien                       '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  '------------------------------------------------'"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  2.Tim theo ten nhan vien                      '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  +------------------------------------------------+"<<endl;
				SET_COLOR(14);
				cout<<"                                                  ( Nhan 0 de quay lai Menu )"<<endl;
                cout<<"                                                  Lua chon: ";cin>>n3;
				cout<<endl;
				if(n3==1){
				SET_COLOR(14);
                cout<<"                                                  Nhap ma nhan vien: ";
   				SET_COLOR(15);
				cin>>s1;
				ds1.timkiemma(s1,ds2,ds3);
				}
				if(n3==2){
				SET_COLOR(14);
                cout<<"                                                  Nhap ten nhan vien: ";
				SET_COLOR(15);
				cin>>s2; s2 = ChuoiInHoa(s2);
				ds1.timkiemten(s2,ds2,ds3);
				}
				if(n3==0) break;
                break;
            case 5:
				cout<<endl;
				SET_COLOR(15);
				cout<<"                                                  +------------------------------------------------+"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  1.Sap xep tang dan                            '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  '------------------------------------------------'"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  2.Sap xep giam dan                            '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  +------------------------------------------------+"<<endl;
				SET_COLOR(14);
				cout<<"                                                  ( Nhan 0 de quay lai Menu )"<<endl;
                cout<<"                                                  Lua chon: ";cin>>n4;
				cout<<endl;
                if(n4==1) {
                    ds1.Sapxep(asc);
                    ds1.xuat(ds2,ds3);
                }
                if(n4==2){
                    ds1.Sapxep(desc);
                    ds1.xuat(ds2,ds3);
                }
				if(n4==0) break;
                break;
            case 6:
				cout<<endl;
				SET_COLOR(15);
				cout<<"                                                  +------------------------------------------------+"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  1.Xoa theo ma                                 '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  '------------------------------------------------'"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  2.Xoa theo ten                                '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  '------------------------------------------------'"<<endl;
                SET_COLOR(14);
				cout<<"                                                  '  3.Xoa theo tuoi                               '"<<endl;
				SET_COLOR(15);
				cout<<"                                                  +------------------------------------------------+"<<endl;
                SET_COLOR(14);
				cout<<"                                                  ( Nhan 0 de quay lai Menu )"<<endl;
                cout<<"                                                  Lua chon: ";cin >>n6;
				if(n6==1){
					SET_COLOR(14);
					cout<<"                                                  Nhap ma nhan vien: ";
					SET_COLOR(15);
					cin >> s3;
					ds1.Xoama(s3);
					ds1.xuat(ds2,ds3);
				}
				if(n6==2){
					SET_COLOR(14);
					cout<<"                                                  Nhap ten nhan vien: ";
					SET_COLOR(15);
					cin >> s4; s4 = ChuoiInHoa(s4);
					ds1.Xoaten(s4);
					ds1.xuat(ds2,ds3);
				}
				if(n6==3){
					SET_COLOR(14);
					cout<<"                                                  Xoa nhan vien co do tuoi tren : ";
					SET_COLOR(15);
					cin >> n9;
					ds1.Xoatuoi(n9);
					ds1.xuat(ds2,ds3);
				}
                if(n6==0) break;
                break;
                break;
			case 7:
					ds2.Nhap();
					ds2.xuat();
                break;
			case 8:
					ds3.Nhap();
					ds3.xuat();
			break;
            case 9:
			ds1.Thongke(ds2,ds3);
            break;
			case 10:
			cout<<endl;
			SET_COLOR(14);
            cout<<"                                                  Nhap ma nhan vien: "; SET_COLOR(15);cin >> s5;
            cin.ignore();
            ds1.SuaThongTin(s5,ds2,ds3);
            break;
            case 11:
            break;

        }
    }
	while(n!=11);
	return 0;
}