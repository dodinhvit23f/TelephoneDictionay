#include<iostream.h>
#include<list>
#include<conio.h>
#include "DirectoryManager.cpp"
#include "File.cpp"
#include "Heapsort.cpp"
#include "merge.cpp"

void AdminMenu(){
	cout<<"1. Them 1 vao danh ba.  "<<endl;
	cout<<"2. Sua 1 phan tu trong danh ba. "<<endl;
	cout<<"3. Xoa 1 phan tu trong danh ba. "<<endl;
	cout<<"4. In ra danh ba. "<<endl;
	cout<<"5. Luu danh ba."<<endl;
	cout<<"6. Sap xep danh ba."<<endl;
	cout<<"7. Tim kiem."<<endl;
	cout<<"8. That toan cuoc dien thoai"<<endl;
	cout<<"0. De thoat."<<endl;
}
void GuestMenu(){
	cout<<"1. In ra danh ba. "<<endl;
	cout<<"2. Luu danh ba."<<endl;
	cout<<"3. Sap xep danh ba."<<endl;
	cout<<"4. Tim kiem."<<endl;
	cout<<"5. Xem  cuoc dien thoai"<<endl;
	cout<<"0. De thoat."<<endl;
}
bool ConfrimAction(){
	cin.ignore();
	cout<<"An Y de tiep tuc . An bat ki de huy  ";
	char confrim;
	cin>>confrim;
	if(confrim=='Y'||confrim == 'y') return true;
	else return false;
}

void AlgorithmMenu(){
	cout<<"1. HeapSort "<<endl;
	cout<<"2. MergeSort"<<endl;
}
void PropertyMenu(){
	cout<<"1. ID\n";
	cout<<"2. Tiem nang\n";
	cout<<"3. Ho va ten\n";
	cout<<"4. Khu vuc\n";
	cout<<"5. Dien thoai\n";
}
void IncreasMenu(){
	cout<<"1. Increas "<<endl;
	cout<<"2. Descreas"<<endl;
}	

void FindDir( list<DanhBa> setList ){
	PropertyMenu();
	int property;
	cin>>property;
	cout<<"Moi Nhap :";
	char temp[30];
	cin.ignore();
	cin.getline(temp,30);
	list<DanhBa> :: iterator itr = setList.end();
	DanhBa sreach;
	if(property == 1)	sreach.setID(atoi(temp));
	if(property == 2)	sreach.setRank(atoi(temp));
	if(property == 3)	sreach.setFullName(string(temp));	 
	if(property == 4)	sreach.setArea(string(temp));
	if(property == 5)	sreach.setPhone(string(temp));
	//	cout<<sreach;
	bool flag = false;
	while(itr != setList.begin()){
	itr--;
	DanhBa single = *itr;
	//cout<<single;
		if(equalsDirectory(single,sreach,property)){
			cout<<single;
			flag = true; 			
		}
	}
	if(!flag) cout<<"Khong tim thay \n";
	cin.ignore();	
}

void SortDir( list<DanhBa> &showList){
	system("cls");
	int property;
	do{
		PropertyMenu();
		cin>>property;
		system("cls");
	}while(property<1||property>5);
	AlgorithmMenu();
	int choice ;
	cin>>choice;	
	int position = 0;
	int listSize = showList.size();
	DanhBa arraylist[listSize];
	//list<DanhBa> :: iterator itr = showList.end();
	copy(showList.begin(),showList.end(),arraylist);
	system("cls");	
	if(choice == 1){
		IncreasMenu();
		cin>>choice;
		if(choice==1) heapSort(arraylist,listSize,false,property);
	else heapSort(arraylist,listSize,true,property);
	} else{
		IncreasMenu();
		cin>>choice;
		if(choice==1) mergeSort(arraylist,0,listSize-1,true,property);
		else mergeSort(arraylist,0,listSize-1,false,property);
	}
	position = 0;
	showList.clear();
	for(position ; position < listSize; position++){					
	showList.push_back(arraylist[position]);
	//	cout<<arraylist[position];
	}
	system("pause");
	cin.ignore();
}

void ShowListDir (	DirectoryManager manager , list<DanhBa> showList,int &page, int &totalPage){
	do{
		system("cls");
		//manager.setList(showList);
		manager.printPage(page,20);
		cout<<"An N de sang tran tiep  . An  P de lui trang \n . An X de thoat ";
		char confrim;
		cin>>confrim;
		if(confrim=='N'||confrim == 'n') page++;
		if(confrim=='P'||confrim == 'p') page--;
		if(confrim=='X'||confrim == 'x') break;
		if(page<1 )  page = 1;
		if(page > totalPage) page--;
		system("cls");
	} while(0<page&&page<=totalPage);				
}

void PrintFile(list<DanhBa> setList, FileAction &file ){
		file.WriteFlie(setList,"D:/DoAn1/DanhBaInra.csv");
		cout<<" Ghi file thanh cong";
		system("pause");
		system("cls");
}
list<DanhBa> ReadFileFreight(list<DanhBa> &setList, FileAction &file){
	cout<<"Dang lay du lieu ....."<<endl;
	 list<DanhBa> temp = file.ReadFileFreight(setList,"D:/DoAn1/freight.csv");
	 if(temp.size()!=0)
		cout<<"Lay xong su lieu"<<endl;
	cin.ignore();
	return temp;
}
void ViewFreight(DanhBa &dir){
	cout<<"Thue Bao: "<< dir.getPhone()<<endl;
	cout<<"Cuoc chua thanh tooan "<<dir.getFare()<<endl;
}
int main(){
	FileAction file;
	DirectoryManager manager;
	//list<DanhBa> showList = file.ReadFile("D:/DoAn1/danhba.csv");
	list<DanhBa> showList = file.ReadFile("D:/DoAn1/danhbatest.csv");
	list<DanhBa> setList ;
//	cout<<showList.size();
	manager.setList(showList);
	setList=manager.getList();
//	manager.printPage(1,5);
	int record = showList.size();
	int totalPage = record/20;
	if( record>20 &&  record%20!=0)totalPage++;
	if( record < 20) totalPage = 1;
	int page=1;
	bool run = true;
	while(run){
		int i ;
		cout<<" chon che do dang nhap.\n 1 Admin. 2 Guest \n";
		cin>> i;
		if(i==1){
			cin.ignore();
			char user[30];
			char password[30];
			cout<<" nhap vao ten dang nhap: ";
			cin.getline(user,30);
			cout<<"nhap vao mat khau ";
			cin.getline(password,30);
			if(strcmp(user,"admin")==0 && strcmp(password,"admin")==0){
			//if(strcmp(user,"admin")==0&&strcmp(password,"admin")==0){
				bool signin = true;
				while(signin){
					system("cls");
					AdminMenu();
					cout<<"Nhap vao lua chon cua ban: ";
					cin>>i;
					cin.ignore();
					switch(i){
						case 1:
							manager.insertOne();
							setList = manager.getList();
						break;
						case 2:
							manager.updateOne();
							setList = manager.getList();
						break;
						case 3:
							manager.removeOne();
							setList = manager.getList();
						break;
						case 4:
							ShowListDir(manager,showList,page,totalPage);
						break;
						case 5:PrintFile(setList,file);
						break;
						case 6: SortDir(showList);
						break;
						case 7: FindDir(setList);
						break;
						case 8: {
							showList = ReadFileFreight(setList,file);
							manager.setList(setList);
							//	list<DanhBa> :: iterator itr = setList.begin();							
						}	
						break;
						case 0:
							signin  = false;
						break;
						default:
						break;
					}
				}
			}
		}else if( i == 2) {
			char number[11];
			cin.ignore();
			cout<<" vui long nhap vao so dien thoai cua ban : ";
			cin.getline(number,11);
			bool signin  = false;
			list<DanhBa> :: iterator itr = showList.begin();
			DanhBa newDir;
			while(itr != showList.end()){
				 newDir = *itr;
				if(newDir.getPhone().compare(string(number))==0){
					signin = true;
					break;
			 	}
			 	itr++;
			}
			if(!signin){
				cout<<" So dien thoai ban nhap vao khong ton tai";
			}
			//number = NULL;
			while(signin){
				system("cls");
				GuestMenu();
				cout<<"Nhap vao lua chon cua ban: ";
				cin>>i;
				cin.ignore();
				switch(i){
					case 0: signin = false;
					break;
					case 1:ShowListDir(manager,showList,page,totalPage);
					break;
					case 2:PrintFile(setList,file);
					break;
					case 3: SortDir(showList);
					break;
					case 4: FindDir(setList);
					break;
					case 5: ViewFreight(newDir);
					cin.ignore();
					default: break;
				}
			}			
		} else{
			 break;
		}
	}
}