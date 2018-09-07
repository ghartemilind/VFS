#define _CRT_SECURE_NO_WARNINGS
#define MAXINODE 50
#define READ 1
#define WRITE 0
#define MAXFILESIZE 1024
#define REGULAR 1
#define SPECIAL2
#define START 0
#define CURRENT 1
#define END 2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>


typedef struct superblock
{
	int TotalInodes;
	int FreeInodes;
}SUPERBLOCK,*PSUPERBLOCK;

typedef struct inode
{
	char FileName[50];
	int InodeNumber;
	int FileSize;
	int FileActualSize;
	int FileType;
	char *Buffer;
	int LinkCount;
	int ReferenceCount;
	int permission;
	
	struct inode*next;
}INODE,*PINODE,**PPINODE;

typedef struct filetable
{
	int readoffset;
	int writeoffset;
	int count;
	int mode;
	PINODE ptrinode;
}FILETABLE,*PFILETABLE;

typedef udft
{
	PFILETABLE ptrfiletable;
}UDFT;

UDFT UDFTArr[50];

SUPERBLOCK SUPERBLOCKsobj;

PINODE head=NULL;

void man(char *name)
{
	if(name==NULL)
	{
		return;
	}
	if(_stricmp(name,"create")==0)
	{
		printf("Description: Use to create new regular file.\n");
		printf("Usage: create File_name Permission\n");
	}
	if(_stricmp(name,"read")==0)
	{
		printf("Description: Use to read data from regular file\n");
		printf("Usage:read File_name No_of_Bytes_To_Read\n");
	}
	elseif(_stricmp(name,"write")==0)
	{
		printf("Description:Use to write in regular file.\n");
		printf("Usage:write File_name \n after this enter the data we want to write\n");
	}
	elseif(_stricmp(name,"ls")==0)
	{
		printf("Description:Use to display information of all files\n");
		printf("Usage:ls\n");
	}
	elseif(_stricmp(name,"stat")==0)
	{
		printf("Description:Use to display information of file\n");
		printf("Usage:stat File_name\n");
	}
	elseif(_stricmp(name,"fstat")==0)
	{
		printf("Description:Use to display information of all files\n");
		printf("Usage:stat File_name\n");
	}
	elseif(_stricmp(name,"truncate")==0)
	{
		printf("Description:Use to remove information from file\n");
		printf("Usage:truncate File_name\n");
	}
	elseif(_stricmp(name,"open")==0)
	{
		printf("Description:Use to open existing file\n");
		printf("Usage: open File_name mode\n");
	}
	elseif(_stricmp(name,"close")==0)
	{
		printf("Description:Use to close opened file\n");
		printf("Usage:close File_name\n	");
	}
	elseif(_stricmp(name,"closeall")==0)
	{
		printf("Description:Use to close all opened file\n");
		printf("Usage:closeall\n");
	}
	elseif(_stricmp(name,"lseek")==0)
	{
		printf("Description:Use to change the file offset\n");
		printf("Usage:lseek File_name ChangeInoffset Start point\n");
	}
	elseif(_stricmp(name,"rm")==0)
	{
		printf("Description:Use to delete file\n");
		printf("Usage:rm File_name\n");
	}
	else
	{
		printf("ERROR:No Manual Entry Available\n");
	}
}

void DisplayHelp()
{
	printf("ls:List out all files\n");
	printf("clear:To clear console\n");
	printf("open:To open the file\n");
	printf("close:To close the file");
	printf("closeall:To closed all opened file\n");
	printf("read:To read contents of file\n");
	printf("write:To write contentsin file\n");
	printf("exit:To terminate the system\n");
	printf("stat:To display information of file using name\n");
	printf("fstat:To display information of file using descriptor\n");
	printf("truncate:To remove all data from files\n");
	printf("rm:Delete the file\n");
}

int GetFDFromName(char * name)
{
	int i=0;
	while(i<50)
	{
		if(UDFTArr[i].ptrfiletable!=null)
		{
			if(_stricmp((UDFTArr[i].ptrfiletable->ptrinode->FileName)name)==0)
				
			break;
		}
		i++;
	}
	if(i==50)
	{
		return -1;
	}
	else
	{
		return i;
	}
}
PINODE GetInode(char * name)
{
	PINODE temp=head;
	
	if(name==NULL)
	{
		return NULL;
	}
	
	while(temp!=NULL)
	{
		if(_stricmp(name,temp->FileName)==0)
			break;
		temp=temp->next;
	}
	return temp;
}

void createDILB()
{
	PINODE newm=NULL;
	PINODE temp=head;
	
	while(i<=MAXINODE)
	{
		newn=(PINODE)malloc(sizeof(INODE));
		newn=LinkCount=newn->ReferenceCount=0;
		newn=FileType=newn->FileSize=0;
		newn Buffer=NULL;
		newn next=NULL;
		newn->InodeNumber=i;
		if(temp==NULL)
		{
			head=newn;
			temp=head;
		}
		else
		{
			temp->next=newn;
			temp=temp->next;
		}
		i++;
	}
}

void InitualizeSuperBlock()
{
	int i=0;
	while(i<50)
	{
		UDFTArr[i].ptrfiletable=NULL;
		i++;
	}
	SUPERBLOCKsobj.TotalInodes=MAXINODE;
	SUPERBLOCKsobj.FreeInodes=MAXINODE;
}

int CreateFile(char *,int permission)
{
	int i=0;
	PINODE temp head;
	
	if((name==NULL)||(permission==0)||(permission>3))
	{
		return -1;
	}
	
	if(SUPERBLOCKsobj.FreeInodes==0)
	{
		return -2;
	}
	
	if(GetInode(name)!=NULL)
	{
		return -3;
	}
	
	(SUPERBLOCKsobj.FreeInodes)--;
	
	while(temp!=NULL)
	{
		if(temp->FileType==0)
			break;
		temp=temp->next;
	}
	
	while(i<50)
	{
		if(UDFTArr[i].ptrfiletable==NULL)
			break;
		i++;
	}
	
	UDFTArr.ptrfiletable=(PFILETABLE)malloc(sizeof(FILETABLE));
	
	if(UDFTArr[i].ptrfiletable==NULL)
	{
		return -4;
	}
	UDFTArr[i].ptrfiletable->count=1;
	UDFTArr[i].ptrfiletable->mode=permission;
	UDFTArr[i].ptrfiletable->readoffset=0;
	UDFTArr[i].ptrfiletable->writeoffset=0;
	
	UDFTArr[i].ptrfiletable->ptrinode=temp;
	stpcpy_s(UDFTArr[i].ptrfiletable->ptrinode->FileName,name);
	
	UDFTArr[i].ptrfiletable->ptrinode->FileType=REGULAR;
	UDFTArr[i].ptrfiletable->ptrinode->ReferenceCount=1;
	UDFTArr[i].ptrfiletable->ptrinode->LinkCount=1;
	UDFTArr[i].ptrfiletable->ptrinode->FileSize=MAXFILESIZE;
	UDFTArr[i].ptrfiletable->ptrinode->FileActualSize=0;
	UDFTArr[i].ptrfiletable->ptrinode->permission=permission;
	UDFTArr[i].ptrfiletable->ptrinode->Buffer=(char * )malloc(MAXFILESIZE);
	memset(UDFTArr[i].ptrfiletable->ptrinode->Buffer,0,1024);
	
	return i;
}

int rm_File(char * name)
{
	int fd=0;
	
	fd=GetFDFromName(name);
	if(fd==-1)
	{
		return -1;
	}

		(UDFTArr[fd].ptrfiletable->ptrinode->LinkCount)--;
		
		(UDFTArr[fd].ptrfiletable->ptrinode->LinkCount==0)
		{
			UDFTArr[fd].ptrfiletable->ptrinode->FileType=0;
			free(UDFTArr[fd].ptrfiletable);
		}
		UDFTArr[fd].ptrfiletable=NULL;
		(SUPERBLOCKsobj.FreeInodes)++;
}

int ReadFile(int fd,char *arr,int size)
{
	int read_size=0;
	
	if(UDFTArr[fd].ptrfiletable=NULL)
	{
		return -1;
	}
	
	if(UDFTArr[fd].ptrfiletable->mode!=READ  && UDFTArr[fd].ptrfiletable->mode!=READ+WRITE)
	{
		return -2;
	}
	
	if(UDFTArr[fd].ptrfiletable->ptrinode->permission!=READ  && UDFTArr[fd].ptrfiletable->ptrinode->permission!=READ+WRITE)
	{
		return -2;
	}

	if(UDFTArr[fd].ptrfiletable->readoffset==UDFTArr[fd].ptrfiletable->ptrinode->FileActualSize)
	{
		return -3;
	}

	if(UDFTArr[fd].ptrfiletable->ptrinode->FileType!=REGULAR)

	read_size=(UDFTArr[fd].ptrfiletable->ptrinode->FileActualSize)-(UDFTArr[fd].ptrfiletable->readoffset);
	
	if(read_size<size)
	{
		strncpy(arr,(UDFTArr[fd].ptrfiletable->ptrinode->Buffer)+(UDFTArr[fd].ptrfiletable->readoffset),read_size)
	
		UDFTArr[fd].ptrfiletable->readoffset=UDFTArr[fd].ptrfiletable->readoffset+read_size;
	}
	else
	{
		strncpy(arr,(UDFTArr[fd].ptrfiletable->ptrinode->Buffer)+(UDFTArr[fd].ptrfiletable->readoffset),size)
	
		UDFTArr[fd].ptrfiletable->readoffset=UDFTArr[fd].ptrfiletable->readoffset+size;
	
	}
	
	return size;
}

int WriteFile(int fd,char *arr,int size)
{
	
	if(((UDFTArr[fd].ptrfiletable->ptrinode->mode)!=WRITE) && ((UDFTArr[fd].ptrfiletable->ptrinode->mode)!=READ+WRITE))
	{
		return -1
	}
	
	
	if(((UDFTArr[fd].ptrfiletable->ptrinode->permission)!=READ)  && ((UDFTArr[fd].ptrfiletable->ptrinode->permission)!=READ+WRITE))
	{
		return -1;
	}
	
	if((UDFTArr[fd].ptrfiletable->writeoffset)==MAXFILESIZE)
	{
		return -2;
	}
	
	if(UDFTArr[fd].ptrfiletable->ptrinode->FileType!=REGULAR)
	{
		return-3;
	}
	
		strncpy(arr,(UDFTArr[fd].ptrfiletable->ptrinode->Buffer)+(UDFTArr[fd].ptrfiletable->writeoffset),size);
	
		(UDFTArr[fd].ptrfiletable->readoffset=UDFTArr[fd].ptrfiletable->writeoffset)+size;
		
		(UDFTArr[fd].ptrfiletable->ptrinode->FileActualSize)=(UDFTArr[fd].ptrfiletable->ptrinode->FileActualSize)+size;
		
		return size;
	
}

int OpenFile(char * name,int mode)
{
	int i=0;
	
	PINODE temp=NULL;
	
	if(name==NULL||mode<=0)
	{
		return -1;
	}
	
	temp=Get_Inode(name);
	
	if(temp==NULL)
	{
		return -2;
	}
	
	if(temp->permission<mode)
	{
		return -3;
	}
	
	while(i<50)
	{
		if(UDFTArr[i].ptrfiletable==NULL)
			break;
		i++;
	}
	
	UDFTArr[i].ptrfiletable=(PFILETABLE)malloc(sizeof(FILETABLE));
	
	if(UDFTArr[i].ptrfiletable==NULL)
	{
		return -1;
	}
	
	UDFTArr[i].ptrfiletable->count=1;

	UDFTArr[i].ptrfiletable->mode=mode;

	if(mode==READ+WRITE)
	{
		UDFTArr[i].ptrfiletable->readoffset=0;
		
		UDFTArr[i].ptrfiletable->writeoffset=0;
	
	}
	if(mode==READ)
	{
		UDFTArr[i].ptrfiletable->readoffset=0;
	}
	
	if(mode==WRITE)
	{
		UDFTArr[i].ptrfiletable->writeoffset=0;
	
	}
	
	UDFTArr[i].ptrfiletable->ptrinode=temp;
	
	(UDFTArr[i].ptrfiletable->ptrinode->ReferenceCount)++;

	return i;
}

void CloseFileByFD(int fd)
{
		UDFTArr[i].ptrfiletable->readoffset=0;
		
		UDFTArr[i].ptrfiletable->writeoffset=0;
		
	(UDFTArr[i].ptrfiletable->ptrinode->ReferenceCount)--;

}

int CloseFileByName(char *name)
{
	
}

