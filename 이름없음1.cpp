#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define up 72
#define down 80
#define st 13
int bing[12][5]={0,};//0,1,2,3,4�� ���κ��� 5,6,7,8,9�� ���κ��� 10,11�� �޴밢���������밢��
void binggo();//�������Ǽ� ���ϱ�
/*------------------------------------------------
����
-------------------------------------------------*/

int p1[25]={0,};
int p2[25]={0,};
int com[25]={0,};
int ai[25]={0,};
int ainum,whatgame=1,turn=0,num,pbin=0,cbin=0;;
//���� �Լ�
void ran(int arr[25]);//�����ǿ� ������ ����
void gameprint(int arr[25]);//������ ���
void myflush();//��ĭ����
void plturn();//�÷��̾���
void comturn();//��ǻ����
int gameset();//���� �Ǽ���

int aim();//�ʱ��߱ް���ġ�迭
int aimput();//�ʱ��߱�ai
int aimput2();//���ai

int comgame();//���� ���� �κ�
int winlose(int arr[25]);//���� �ټ� �Ǵ�
int gameend();//������ӽ�������
int arrcl(int arr[25],int n);//�Է¹��� ����ü
int arrcl2(int arr[25],int n);//�Է¹��� ����ü


int main()
{
    char enter=0;
    binggo();
    srand(time(NULL));
    ran(com);
    ran(p1);
    while(enter!=st){
        system("cls");
        if(whatgame==1){
            printf("    ��������\n >  1.�ʱ�\n    2.�߱�\n    3.���\n    4.����\n    5.������\n");}
        if(whatgame==2){
            printf("    ��������\n    1.�ʱ�\n >  2.�߱�\n    3.���\n    4.����\n    5.������\n");}
        if(whatgame==3){
            printf("    ��������\n    1.�ʱ�\n    2.�߱�\n >  3.���\n    4.����\n    5.������\n");}
        if(whatgame==4){
            printf("    ��������\n    1.�ʱ�\n    2.�߱�\n    3.���\n >  4.����\n    5.������\n");}
        if(whatgame==5){
            printf("    ��������\n    1.�ʱ�\n    2.�߱�\n    3.���\n    4.����\n >  5.������\n");}


        enter = getch();
        if(enter==-32) enter=getch();
        if(enter==down){
            if(whatgame!=5){
                whatgame++;
            }
        }
        if(enter==up){
            if(whatgame!=1){
                whatgame--;
            }
        }

    }
    system("cls");

    if(whatgame==5){
        return 0;}
    else{
    comgame();
    }

}

void binggo(){
int i,j;
for(i=0;i<12;i++){
for(j=0;j<5;j++){
if(i<5){
bing[i][j]=j+i*5;
}
else if(i<10){
bing[i][j]=j*5+i-5;
}
else if(i==10){
bing[i][j]=4*(j+1);
}
else{
bing[i][j]=6*j;
}
}
}
}


int comgame(){
    int io=1,t;
    if(whatgame==2){
     for(int i=0;i<5;i++){
        ai[6*i]++;
        //ai[5*i+2]++;
        ai[4*(i+1)]++;
        //ai[10+i]++;
    }
}
    t=gameset();
    while(1){
     if(t==1){
         plturn();
         io=gameend();
         if(io==0){
             break;
          }
          t=0;
     }
     else{
         comturn();
         io=gameend();
         if(io==0){
            break;
         }
         t=1;
        }
    }
}

int winlose(int arr[25]){
    int i;
    int cnt = 0;
    for(i=0;i<12;i++){
     if(arr[bing[i][0]]==0 && arr[bing[i][1]]==0 && arr[bing[i][2]]==0 && arr[bing[i][3]]==0 && arr[bing[i][4]]==0 ) cnt++;

    }
    return cnt;
}


int arrcl(int arr[25],int n){//�Է¹��� ���� üũ�ϱ�
    int i;
    int k=2;
    for(i=0;i<25;i++){
        if(arr[i]==n){
            arr[i]=0;
            k=1;

        }
    }

    return k;
}

int arrcl2(int arr[25],int n){//�Է¹��� ���� üũ�ϱ�
    int i;
    int k=2;
    for(i=0;i<25;i++){
        if(arr[i]==n){
            arr[i]=0;
            k=1;

            ai[i]=-1;
            ainum=i;
        }
    }

    return k;
}

void ran(int arr[25]){
    int i,n,j;
    for(i=0;i<25;i++){
        n=rand()%25+1;
        arr[i]=n;
        for(j=0;j<i;j++){//�ߺ� �˻�
            if(arr[i]==arr[j]) i--;
        }
    }

}

void gameprint(int arr[25]){
    int cnt = 0;
    int i,j;
    for(i=0;i<11;i++){
        if(i%2==0){
            printf("+--+--+--+--+--+");
        }else{
            for(j=0;j<11;j++){
                if(j%2==1){
                    if(arr[cnt]==0){
                        printf("%2s","��");

                    }else{
                        printf("%2d",arr[cnt]);
                    }
                    cnt++;
                }else{
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}

int aimput(){
    int i,j,r;
    int king=0;
    int qq[25]={0,};
    int cnt=0;
    for(i=0;i<25;i++){
        if(ai[i]>king){
            king=ai[i];
            for(j=0;j<25;j++){
                qq[j]=0;
            }
            cnt=0;
        }
        if(ai[i]==king){
            qq[cnt]=i;
            cnt++;
        }
    }
    srand(time(NULL));
    r=rand()%cnt;
   return com[qq[r]];
}

void myflush(){
    while(getchar()!='\n'){;}
}

int gameset(){
srand(time(NULL));
int wn,y,res;
char n1='a';
    int cnt=5;
    while(n1!='n'){
        system("cls");
        gameprint(p1);
        printf("\n������ȸ = %d\n�ٽ� ���ڽ��ϱ�?(y/n) ",cnt);
        scanf("%c",&n1);
        if(n1=='y'){
            cnt--;
            ran(p1);
            if(cnt==0) break;
        }
    }
    system("cls");
    printf("������������ ���ϰڽ��ϴ�!! (������ �ո�:1,������ �޸�:2)\n");
    scanf("%d",&wn);
    while(wn!=1&&wn!=2){
     printf("�߸� �Է��߽��ϴ�. �ٽ� �Է��� �ּ���. ");
     myflush();
     scanf("%d",&wn);
}
    system("cls");
y=rand()%3;
if(y==1){
printf("������ �ո��� ���Խ��ϴ�\n");
if(wn==y){
printf("�÷��̾ ���� �����մϴ�");
Sleep(1700);
return 1;}
else{
printf("��ǻ�Ͱ� ���� �����մϴ�");
Sleep(1700);
return 0;}
}
else{
printf("������ �޸��� ���Խ��ϴ�\n");
if(wn==y){
printf("�÷��̾ ���� �����մϴ�");
Sleep(1500);
return 1;}
else{
printf("��ǻ�Ͱ� ���� �����մϴ�");
Sleep(1500);
return 0;}
}
}
void plturn(){
    int compare,num,res;
        srand(time(NULL));
        system("cls");
        gameprint(p1);
        printf("\n����� �� �� : %d\n�÷��̾� ����� : %d\n��ǻ�� ����� : %d\n�÷��̾��� �����Դϴ�.\n���� �Է��� �ּ���. ",turn,pbin,cbin);
        res = scanf("%d", &num);

        compare = arrcl(p1,num);
        if(compare==2){
            while(compare==2){
                printf("�߸� �Է��߽��ϴ�. �ٽ� �Է��� �ּ���. ");
                myflush();
                res = scanf("%d",&num);
                compare = arrcl(p1,num);
            }
        }
        turn++;
        arrcl2(com, num);
        if(whatgame==1||whatgame==2){
aim();}
        pbin = winlose(p1);
        cbin = winlose(com);
        Sleep(500);
}

void comturn(){
    int compare=2,r;
        while(compare==2){
         if(whatgame==1||whatgame==2){
             r=aimput();}
            else if(whatgame==3){
             r=aimput2();}
            compare = arrcl2(com,r);
        }
        if(whatgame==1||whatgame==2){
aim();}
        system("cls");
        gameprint(p1);
        printf("\n����� �� �� : %d\n�÷��̾� ����� : %d\n��ǻ�� ����� : %d\n��ǻ���� �����Դϴ�. ��ǻ�Ͱ� �� �� : %d\n",turn,pbin,cbin,r);
arrcl(p1,r);
        pbin = winlose(p1);
        cbin = winlose(com);
        Sleep(1000);

    }


int gameend(){
        if(pbin>=4&&cbin>=4){
         system("cls");
        gameprint(p1);
        printf("\n����� �� �� : %d\n�÷��̾� ����� : %d\n��ǻ�� ����� : %d\n",turn,pbin,cbin);
            printf("�����ϴ�");
            return 0;
        }
        else if(pbin>=4){
         system("cls");
        gameprint(p1);
        printf("\n����� �� �� : %d\n�÷��̾� ����� : %d\n��ǻ�� ����� : %d\n",turn,pbin,cbin);
        printf("�÷��̾ �̰���ϴ�.\n");
            return 0;
        }else if(cbin>=4){
         system("cls");
        gameprint(p1);
        printf("\n����� �� �� : %d\n�÷��̾� ����� : %d\n��ǻ�� ����� : %d\n",turn,pbin,cbin);
        printf("�÷��̾ �����ϴ�.\n");
            return 0;
        }
        return 1;
}

int aim(){
    int i;
    for(i=1;i<5;i++){
        if(i==1){
            if(ainum+i<25&&ai[ainum+i]!=-1){
                ai[ainum+i]=ai[ainum+i]+1;}
            if(ainum-i>=0&&ai[ainum-i]!=-1){
                ai[ainum-i]=ai[ainum-i]+1;}
        }
        else{
            if(ainum+i+2<25&&ai[ainum+i+2]!=-1){
                ai[ainum+i+2]=ai[ainum+i+2]+1;}
            if(ainum-i-2>=0&&ai[ainum-i-2]!=-1){
                ai[ainum-i-2]=ai[ainum-i-2]+1;}
        }
        }
    }
int aimput2(){
int aibeta[12]={0,};//0,1,2,3,4�� ���κ��� 5,6,7,8,9�� ���κ��� 10,11�� �޴밢���������밢��
int c[12]={0,1,2,3,4,5,6,7,8,9,10,11};
    int qq[25]={0,};
int i,j,ch,king=0,cnt=0,r;
    for(i=0;i<12;i++){
     aibeta[i]=ai[bing[i][0]]+ai[bing[i][1]]+ai[bing[i][2]]+ai[bing[i][3]]+ai[bing[i][4]];
    }
for(i=0;i<4;i++){
for(j=i+1;j<12;j++){
if(aibeta[i]>=aibeta[j]){
ch=aibeta[i];
aibeta[i]=aibeta[j];
aibeta[j]=ch;
ch=c[i];
c[i]=c[j];
c[j]=ch;
}
}
}
for(i=0;i<4;i++){
for(j=0;j<5;j++){
if(ai[bing[c[i]][j]]!=-1){
ai[bing[c[i]][j]]=ai[bing[c[i]][j]]+1;}
}
}
for(i=0;i<25;i++){
        if(ai[i]>king){
            king=ai[i];
            for(j=0;j<25;j++){
                qq[j]=0;
            }
            cnt=0;
        }
        if(ai[i]==king){
            qq[cnt]=i;
            cnt++;
        }
    }
    for(j=0;j<25;j++){
if(ai[j]!=-1){
                ai[j]=0;}
            }

    srand(time(NULL));
            r=rand()%cnt;
   return com[qq[r]];


}
