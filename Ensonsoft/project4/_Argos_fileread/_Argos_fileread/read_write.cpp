#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class FileRW{
public:
	void read(const string& fname){

		char str[200];

		ifstream fin;
		fin.open(fname.c_str());
		if(fin.good()){
			cout<<fname.c_str()<<"을 읽고 있습니다."<<endl;
		}
		if(fin.fail()){
			cout<<"파일 이름을 잘못 입력했습니다."<<endl;
		}

		int menu = 99;

		

		//char* save = "[SAVE]";
		//char* view = "[VIEW]";
		//char* stream = "[STREAM]";
		//char* argos = "[ARGOS]";
		//char* sender = "[SENDER]";
		//char* manager = "[MANAGER]";

		while((fin.getline(str,150))!=NULL)
		{

			char* _str = str;

			char* common = "[COMMON]";
			menu = strcmp(str,common);

			if(menu==0)
			{
				
				char* site_code_flag = "site_code=";
				char* site_code = "inite code";
				
				fin.getline(str,150);
				int site_code_index = strncmp(str,site_code_flag,strlen(site_code_flag));
				if(!site_code_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* site_name_flag = "site_name=";
				char* site_name = "inite name";

				fin.getline(str,150);
				int site_name_index = strncmp(str,site_name_flag,strlen(site_name_flag));
				if(!site_name_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* TriggerMode_flag = "TriggerMode=";
				char* TriggerMode = "inite TriggerMode";

				fin.getline(str,150);
				int TriggerMode_index = strncmp(str,TriggerMode_flag,strlen(TriggerMode_flag));
				if(!TriggerMode_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* ReadyQ_Count_flag = "ReadyQ_Count=";
				char* ReadyQ_Count = "inite ReadyQ_Count";

				fin.getline(str,150);
				int ReadyQ_Count_index = strncmp(str,ReadyQ_Count_flag,strlen(ReadyQ_Count_flag));
				if(!ReadyQ_Count_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* DispQ_Count_flag = "DispQ_Count=";
				char* DispQ_Count = "inite DispQ_Count";

				fin.getline(str,150);
				int DispQ_Count_index = strncmp(str,DispQ_Count_flag,strlen(DispQ_Count_flag));
				if(!DispQ_Count_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* time_expire_sec_flag = "time_expire_sec=";
				char* time_expire_sec = "inite time_expire_sec";

				fin.getline(str,150);
				int time_expire_sec_index = strncmp(str,time_expire_sec_flag,strlen(time_expire_sec_flag));
				if(!time_expire_sec_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* Exposure_RecogCount_flag = "Exposure_RecogCount=";
				char* Exposure_RecogCount = "inite Exposure_RecogCount";

				fin.getline(str,150);
				int Exposure_RecogCount_index = strncmp(str,Exposure_RecogCount_flag,strlen(Exposure_RecogCount_flag));
				if(!Exposure_RecogCount_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* IO_Config_Mode_flag = "IO_Config_Mode=";
				char* IO_Config_Mode = "inite IO_Config_Mode";

				fin.getline(str,150);
				int IO_Config_Mode_index = strncmp(str,IO_Config_Mode_flag,strlen(IO_Config_Mode_flag));
				if(!IO_Config_Mode_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* ViolationSpeed_flag = "ViolationSpeed=";
				char* ViolationSpeed = "inite ViolationSpeed";

				fin.getline(str,150);
				int ViolationSpeed_index = strncmp(str,ViolationSpeed_flag,strlen(ViolationSpeed_flag));
				if(!ViolationSpeed_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
			}

			menu++;

			char* save = "[SAVE]";
			menu = strcmp(str,save);

			if(menu==0)
			{
				char* SavePath_flag = "SavePath=";
				char* SavePath = "inite";

				fin.getline(str,150);
				int SavePath_index = strncmp(str,SavePath_flag,strlen(SavePath_flag));
				if(!SavePath_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* backup_path_flag = "backup_path=";
				char* backup_path = "inite";

				fin.getline(str,150);
				int backup_path_index = strncmp(str,backup_path_flag,strlen(backup_path_flag));
				if(!backup_path_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* keep_store_days_flag = "keep_store_days=";
				char* keep_store_days = "inite";

				fin.getline(str,150);
				int keep_store_days_index = strncmp(str,keep_store_days_flag,strlen(keep_store_days_flag));
				if(!keep_store_days_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* log_store_days_flag = "log_store_days=";
				char* log_store_days = "inite";

				fin.getline(str,150);
				int log_store_days_index = strncmp(str,log_store_days_flag,strlen(log_store_days_flag));
				if(!log_store_days_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* SaveWidth_flag = "SaveWidth=";
				char* SaveWidth = "inite";

				fin.getline(str,150);
				int SaveWidth_index = strncmp(str,SaveWidth_flag,strlen(SaveWidth_flag));
				if(!SaveWidth_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* SaveHeight_flag = "SaveHeight=";
				char* SaveHeight = "inite";

				fin.getline(str,150);
				int SaveHeight_index = strncmp(str,SaveHeight_flag,strlen(SaveHeight_flag));
				if(!SaveHeight_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* CompanyFormat_flag = "CompanyFormat=";
				char* CompanyFormat = "inite";

				fin.getline(str,150);
				int CompanyFormat_index = strncmp(str,CompanyFormat_flag,strlen(CompanyFormat_flag));
				if(!CompanyFormat_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* InsertPlate_flag = "InsertPlate=";
				char* InsertPlate = "inite";

				fin.getline(str,150);
				int InsertPlate_index = strncmp(str,InsertPlate_flag,strlen(InsertPlate_flag));
				if(!InsertPlate_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* SequenceImgCount_flag = "SequenceImgCount=";
				char* SequenceImgCount = "inite";

				fin.getline(str,150);
				int SequenceImgCount_index = strncmp(str,SequenceImgCount_flag,strlen(SequenceImgCount_flag));
				if(!SequenceImgCount_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* SaveFormat_flag = "SaveFormat=";
				char* SaveFormat = "inite";

				fin.getline(str,150);
				int SaveFormat_index = strncmp(str,SaveFormat_flag,strlen(SaveFormat_flag));
				if(!SaveFormat_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
			}	
			menu++;

			char* view = "[VIEW]";
			menu = strcmp(str,view);

			if(menu==0)
			{
				char* Width_flag = "Width=";
				char* Width = "inite";

				fin.getline(str,150);
				int Width_index = strncmp(str,Width_flag,strlen(Width_flag));
				if(!Width_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* Height_flag = "Height=";
				char* Height = "inite";

				fin.getline(str,150);
				int Height_index = strncmp(str,Height_flag,strlen(Height_flag));
				if(!Height_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
			}
			menu++;

			char* stream = "[STREAM]";
			menu = strcmp(str,stream);

			if(menu==0)
			{
				
				char* Width_flag = "Width=";
				char* Width = "inite";

				fin.getline(str,150);
				int Width_index = strncmp(str,Width_flag,strlen(Width_flag));
				if(!Width_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* Height_flag = "Height=";
				char* Height = "inite";

				fin.getline(str,150);
				int Height_index = strncmp(str,Height_flag,strlen(Height_flag));
				if(!Height_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* PlateWidth_flag = "PlateWidth=";
				char* PlateWidth = "inite";

				fin.getline(str,150);
				int PlateWidth_index = strncmp(str,PlateWidth_flag,strlen(PlateWidth_flag));
				if(!PlateWidth_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* PlateHeight_flag = "PlateHeight=";
				char* PlateHeight = "inite";

				fin.getline(str,150);
				int PlateHeight_index = strncmp(str,PlateHeight_flag,strlen(PlateHeight_flag));
				if(!PlateHeight_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* PlatePositionBottom_flag = "PlatePositionBottom=";
				char* PlatePositionBottom = "inite";

				fin.getline(str,150);
				int PlatePositionBottom_index = strncmp(str,PlatePositionBottom_flag,strlen(PlatePositionBottom_flag));
				if(!PlatePositionBottom_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* bitrate_flag = "bitrate=";
				char* bitrate = "inite";

				fin.getline(str,150);
				int bitrate_index = strncmp(str,bitrate_flag,strlen(bitrate_flag));
				if(!bitrate_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* StreamName_flag = "StreamName=";
				char* StreamName = "inite";

				fin.getline(str,150);
				int StreamName_index = strncmp(str,StreamName_flag,strlen(StreamName_flag));
				if(!StreamName_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* StreamPort_flag = "StreamPort=";
				char* StreamPort = "inite";

				fin.getline(str,150);
				int StreamPort_index = strncmp(str,StreamPort_flag,strlen(StreamPort_flag));
				if(!StreamPort_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
			}
			menu++;

			char* argos = "[ARGOS]";
			menu = strcmp(str,argos);

			if(menu==0)
			{
				
				char* udp_port_flag = "udp_port=";
				char* udp_port = "inite";

				fin.getline(str,150);
				int udp_port_index = strncmp(str,udp_port_flag,strlen(udp_port_flag));
				if(!udp_port_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}

				char* udp_alive_period_flag = "udp_alive_period=";
				char* udp_alive_period = "inite";

				fin.getline(str,150);
				int udp_alive_period_index = strncmp(str,udp_alive_period_flag,strlen(udp_alive_period_flag));
				if(!udp_alive_period_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
			}
			menu++;

			char* sender = "[SENDER]";
			menu = strcmp(str,sender);

			if(menu==0)
			{
			
				char* fileserver_ip_flag = "fileserver_ip=";
				char* fileserver_ip = "inite";

				fin.getline(str,150);
				int fileserver_ip_index = strncmp(str,fileserver_ip_flag,strlen(fileserver_ip_flag));
				if(!fileserver_ip_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* fileserver_port_flag = "fileserver_port=";
				char* fileserver_port = "inite";

				fin.getline(str,150);
				int fileserver_port_index = strncmp(str,fileserver_port_flag,strlen(fileserver_port_flag));
				if(!fileserver_port_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* file_gathering_time_flag = "file_gathering_time=";
				char* file_gathering_time = "inite";

				fin.getline(str,150);
				int file_gathering_time_index = strncmp(str,file_gathering_time_flag,strlen(file_gathering_time_flag));
				if(!file_gathering_time_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* udp_port_flag = "udp_port=";
				char* udp_port = "inite";

				fin.getline(str,150);
				int udp_port_index = strncmp(str,udp_port_flag,strlen(udp_port_flag));
				if(!udp_port_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
				
				char* udp_alive_period_flag = "udp_alive_period=";
				char* udp_alive_period = "inite";

				fin.getline(str,150);
				int udp_alive_period_index = strncmp(str,udp_alive_period_flag,strlen(udp_alive_period_flag));
				if(!udp_alive_period_index)
				{
					_str=strchr(str,'=');
					_str++;
					cout<<_str<<endl;
				}
			}
		}
		fin.close();
	}
	void write(const string& fname,bool append=true,const char* chs="hello."){
		ofstream fout;
		if(append){
			fout.open(fname.c_str(),ios_base::app);
		}else{
			fout.open(fname.c_str());
		}

		if(fout.fail()){
			cout<<"파일 출력에 실패했습니다.";
			return;
		}
		fout<<chs<<endl;

		fout.close();
	}
};
int main(){

	char chs[]="void write(){";
	FileRW* fr= new FileRW;

	fr->read("setting.ini");
	fr->write("_setting.ini",true,chs);
	delete fr;
	system("PAUSE");
	return EXIT_SUCCESS;
}