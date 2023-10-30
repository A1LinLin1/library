#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"windows.h"
typedef int Status;
#define OK 1
typedef struct proc{
	int PID;
	char state[10];
	int time;
	int prior;
	struct proc *next;
}*PCB,pcb;
Status InitList(PCB &L){
	L=(PCB)malloc(sizeof(pcb));
	L->PID=0;
	L->time=0;
	L->prior=-10;
	L->next=NULL;
	return OK;
}
Status Insert(PCB &L,PCB p){//将各个情况的结点自大到小插入
	PCB pb=NULL,pf=NULL;
	pf=L;
	if(L==NULL){
		L=p;
		p->next=NULL;
	}
	while((p->prior<=pf->prior) && (pf->next!=NULL)){
		pb=pf;					//得到指针的前一个结点的指针
		pf=pf->next;
	}
	if(p->prior>pf->prior){
		if(pf==L){
			L=p;
			p->next=pf;
		}
		else{
			pb->next=p;
			p->next=pf;
		}
	}
	else{
		pf->next=p;
		p->next=NULL;
	}
	return OK;
}
Status CreatReadyPcb(PCB &L_Ready){//就绪递减队列
	InitList(L_Ready);
	PCB p,p1,q;
	p1=L_Ready;
	int i,n;
	printf("输入进程个数:\n");
	scanf("%d",&n);
	printf("输入进程信息:\n");
	for(i=0;i<n;i++){
		p=(PCB)malloc(sizeof(pcb));
		printf("输入进程的内部标识(PID),时间片(time),优先级(prior):\n");
		scanf("%d %d %d",&p->PID,&p->time,&p->prior);
		strcpy(p->state,"ready");
		Insert(L_Ready,p);
	}
	PCB pp;//加入空的头结点,之前忘加了...
	InitList(pp);
	pp->next=L_Ready;
	L_Ready=pp;
	printf("*****优先级就绪队列建立成功!*****\n");
	return OK;
}

Status DeleteList(PCB &L){
	int j=0;
	PCB p,q;
	p=L;
	q=p->next;
	p->next=q->next;
	free(q);
	return OK;
}
void fuZhi(PCB &p1,PCB &p2){
	InitList(p1);
	p1=(PCB)malloc(sizeof(pcb));
	p1->PID=p2->PID;
	p1->time=p2->time;
	p1->prior=p2->prior;
	p1->next=NULL;
}
void RunPcb(PCB &L_Ready,PCB &L_Block,PCB &L_Finish){
	int n,count=0;
	PCB p=L_Ready->next,p0,p2,pp,p4,pp1;
	PCB p1=L_Finish;
	PCB p5,ppp1;
	printf("请输入阻塞数:\n");
	scanf("%d",&n);
	if(p->time!=n){//不阻塞
		if(p->time!=0){//时间片不为0
			p->time=(p->time)-1;
			p->prior=(p->prior)-1;
			if(p->time!=0){
				fuZhi(p2,p);
				DeleteList(L_Ready);

				p4=L_Ready;//除去头结点
				L_Ready=L_Ready->next;
				free(p4);
				strcpy(p2->state," ready ");
				Insert(L_Ready,p2);//这个函数只能对没有头结点的链表操作

				InitList(pp1);//加入空的头结点
				pp1->next=L_Ready;
				L_Ready=pp1;
				//strcpy(L_Ready->next->state,"ready");
			}
			else{
				fuZhi(p5,p);
				DeleteList(L_Ready);
				strcpy(p5->state," finish ");
				Insert(L_Finish,p5);//这个函数只能对没有头结点的链表操作
			}
		}
		else{//时间片为零
			fuZhi(p2,p);
			DeleteList(L_Ready);
			strcpy(p2->state," finish ");
			Insert(L_Finish,p2);
		}
	}
	else{
		fuZhi(p2,p);
		DeleteList(L_Ready);
		strcpy(p2->state," block ");
		Insert(L_Block,p2);
	}
}
void printPcb(PCB &L_Ready,PCB &L_Block,PCB &L_Finish){
	PCB p1,p2,p3;
	p1=L_Ready->next;
	p2=L_Block;
	p3=L_Finish;
	printf("----------优先级就绪队列为:----------\n");
	while(p1!=NULL && p1->prior!=-10){
		printf("PID( %d )---state( %s )---need time( %d )---优先级(%d)\n",p1->PID,p1->state,p1->time,p1->prior);
		p1=p1->next;
	}
	printf("----------阻塞队列为:----------\n");
	while(p2!=NULL && p2->prior!=-10){
		printf("PID( %d )---state( %s )---need time( %d )---优先级(%d)\n",p2->PID,p2->state,p2->time,p2->prior);
		p2=p2->next;
	}
	printf("----------终止队列为:----------\n");
	while(p3!=NULL && p3->prior!=-10){
		printf("PID( %d )---state( %s )---need time( %d )---优先级(%d)\n",p3->PID,p3->state,p3->time,p3->prior);
		p3=p3->next;
	}
}
int main(){
	PCB L_Ready,L_Block,L_Finish;
	int n;
	printf("******************************\n");
	printf("1--->初始化\n");
	printf("2--->创建就绪队列\n");
	printf("3--->运行\n");
	printf("4--->唤醒\n");
	printf("5--->打印所有队列中的进程信息\n");
	printf("0--->测试结束\n");
	printf("******************************\n");
	while(n!=0){
		printf("请输入你的选择:\n");
		scanf("%d",&n);
		switch(n){
		case 1:
			InitList(L_Block);
			InitList(L_Finish);
			printf("初始化成功!\n");
			break;
		case 2:
			CreatReadyPcb(L_Ready);
			printPcb(L_Ready,L_Block,L_Finish);
			break;
		case 3:
			RunPcb(L_Ready,L_Block,L_Finish);
			printPcb(L_Ready,L_Block,L_Finish);
			break;
		case 4:
		case 5:
			printPcb(L_Ready,L_Block,L_Finish);
			break;
		}
	}
	return 0;
}
