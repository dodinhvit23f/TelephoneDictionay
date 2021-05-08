#include<iostream.h>
#include<list>
#include<string>
#include<iterator>  
#include "DanhBa.cpp"
using namespace std;

class DirectoryManager {
	private : 
		list<DanhBa> listDir;
	public :
	
		list<DanhBa> getList(){
			return listDir;
		}	
		
		void setList(list<DanhBa> &li){
			listDir.clear();
			list<DanhBa> :: iterator itr = li.begin();
			while(itr != li.end()){
		 		this->listDir.push_front(*itr);
				itr++;
			}
			//this->listDir = li;
		}
		// insert into the last of list
		void insertOne(){
			DanhBa Newdirec;
		
			cout<<" Nhap vao Ho va Ten: ";
			char templ[40];	
			cin.getline(templ,40);
			string fullname = string(templ);
			
			cout<<" Nhap vao so dien thoai: ";
			cin.getline(templ,40);
			string phone = string(templ);
			
			cout<<" Nhap vao khu vuc: ";
			cin.getline(templ,40);
			string area = string(templ);
			int rank;
			do{
				cout<<" Nhap tiem nang: (1 - 5)";
				cin>>rank;	
			}while( rank <1|| rank >5);
			cin.ignore();
			int Id = (listDir.back().getID()<0)? 1 : listDir.back().getID()+1;
			Newdirec.Input(Id,fullname,phone,area,rank);
			list<DanhBa> :: iterator  itr = listDir.end();
			listDir.push_back(Newdirec);
		}
		
		// remove . take the object need to remove , to last of list and delete it
		void removeOne(){
			int ID;
			cout<<" Nhap vao Id phan tu can xoa: ";
			cin>>ID;
			list<DanhBa> :: iterator  itr = listDir.begin();
			DanhBa Direc;
			Direc.setID(ID);
			
			while(itr != listDir.end()){
				if(*itr == Direc){
					list<DanhBa> :: iterator  Newitr = itr;
					while(Newitr != listDir.end()){
						Newitr++;
						if(Newitr != listDir.end()) *itr  = *Newitr;
						itr++;
						//	cout<<" lap";
						//if(itr!=listDir.end())itr++;
					}	
				}
				itr++;
			}
				
			listDir.pop_back();
		}
		
		// find the object by Id and change it
		void updateOne(){
			int ID;
			cout<<" Nhap vao Id cua phan tu can sua: ";
			cin>>ID;
			list<DanhBa> :: iterator  itr = listDir.begin();
			DanhBa Direc;
			Direc.setID(ID);
			while(itr != listDir.end()){			
				if(*itr == Direc){
					cin.ignore();
					cout<<" Nhap vao Ho va Ten: ";
					char templ[40];	
					cin.getline(templ,40);
					string fullname = string(templ);
					
					cout<<" Nhap vao so dien thoai: ";
					cin.getline(templ,40);
					string phone = string(templ);
					
					cout<<" Nhap vao khu vuc: ";
					cin.getline(templ,40);
					string area = string(templ);
					int rank;
					do{
						cout<<" Nhap tiem nang: (1 - 5)";
						cin>>rank;	
					}while( rank <1|| rank >5);
					Direc.setFullName(fullname);
					Direc.setPhone(phone);
					Direc.setArea(area);
					Direc.setRank(rank);
					*itr = Direc;
				}
			itr++;
			}
		}
		// find by id
		void Find(){
			int ID;
			cout<<" Nhap vao Id: ";
			cin>>ID;
			list<DanhBa> :: iterator  itr = listDir.begin();
			DanhBa Direc;
			Direc.setID(ID);
			while(itr != listDir.end()){
				if(*itr == Direc){
					cout<< 	*itr;
				}
			}
		}
		// print the list by page 
		void printPage(int page,int record){
			list<DanhBa> :: iterator  itr = listDir.begin();
			int start = ((page < 2)? 0 : page-1)*record;
			int end   = page*record;
			int count = 0;
			while(itr != listDir.end()){
				if(count >= start && count <end)cout<<*itr;
				if(count > end) break;
				itr++;
				count++;
			}
		}
		
		void printAll(){
			list<DanhBa> :: iterator  itr = listDir.begin();
			while(itr != listDir.end()){
			cout<<*itr;
			itr++;	
			}
		}
};


