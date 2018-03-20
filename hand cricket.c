#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int flag=0,e,f,target;
int batting();
int bowling();
int main()
{
    int a,b,c,d,e,f;
    printf("toss\n");
    printf("Say head or tail\n");
    printf("1.head\n2.tail\n");
    scanf("%d",&a);
    if((a<=0)||(a>2))
        exit(0);
    b=abs(rand())%3;
    if(a==b)
    {
        printf("You won the toss\n");
        printf("Enter your choice\n1.batting\n2.bowling\n");
        scanf("%d",&c);
        if(c==1)
        {
            printf("you won the toss and elected to bat first\n");
            e=batting();
            flag=2;
            target=e+1;
            printf("your score is %d\n",e);
            printf("computer target is %d\n",target);
            printf("defend the target\n");
            f=bowling();
        }
        else
        {
            printf("you won the toss and elected to bowl first\n");
            f=bowling();
            flag=1;
            target=f+1;
            printf("your target is %d\n",target);
            e=batting();
        }
    }
    else
    {
        d=abs(rand())%2;
        if(d==1)
        {
            printf("computer have won the toss and elected to bat first\n");
            f=bowling();
            flag=1;
            target=f+1;
            printf("your target is %d\n",target);
            e=batting();
        }
        else
        {
            printf("computer have won the toss and elected to field first\n");
            e=batting();
            flag=2;
            target=e+1;
            printf("computer target is %d\n",target);
            printf("defend the target\n");
            f=bowling();
        }
    }
    printf("your score is %d\n",e);
    printf("computer score is %d\n",f);
    if(e>f)
        {
            printf("you won the match\n");
            if(flag==2)
                printf("you won by %d\n",e-f);
        }
    else if(e<f)
        {
            printf("you lost the match\n");
            if(flag==1)
            printf("you lost by %d\n",f-e);
        }
    else
        {
            printf("Score are level\n");
            printf("Match draw\n");
        }
    return 0;
}
int batting()
{
    int n,m,score=0;
    while(m!=n)
    {
        printf("Enter your shot\n");
        scanf("%d",&n);
        if((n>6)||(n<=0))
            exit(0);
        m=abs(rand())%7;
        printf("computer ball is %d\n",m);
        score=score+n;
        if(m==n)
        {
            score=score-n;
            printf("Out\n");
        }
        if((flag==1)&&(score>=target))
            break;
    }
    return score;
}
int bowling()
{
    int n,m,score=0;
    while(m!=n)
    {
        printf("Enter your bowling score\n");
        scanf("%d",&n);
        if((n>6)||(n<=0))
            exit(0);
        m=abs(rand())%7;
        printf("computer shot is %d\n",m);
        score=score+m;
        if(m==n)
        {
            score=score-m;
            printf("out\n");
        }
        if((flag==2)&&(score>=target))
            break;
    }
    return score;
}
