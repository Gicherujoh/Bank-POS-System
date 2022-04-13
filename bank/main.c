#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Customer
{
    
    char name[20];
    char gender[6];
    int idNo,mobileNo,pass,pass1,accountNo,t;
    int Amount,total;
    int withdraw;
    int number;
    int rloan;
    int ploan,payloan;
    int balance;
    int interest;
    int transcaction;
    
}Customer;

void Time(){
    time_t  t;
    time(&t);
    printf("%s",ctime(&t));
}
int lower=10035,upper=50035;
void Signin(){
    Customer c;
    FILE *fp;
    fp = fopen("/home/sammy/Downloads/File Project/Bank 1.c","w");
      printf("Set New Password:");
      scanf("%d",&c.pass);
      printf("Confirm Your Password:");
       scanf("%d",&c.pass1);
       if(c.pass!=c.pass1){
           printf("Password does not match. Try Again.\n");
               Signin();//recursion.
       }
          else
          {
               printf("You have successfully set you password: Continue\n");
          }  
    printf("Please Enter Your Details:\n");
    printf("Name:");
    scanf("%s",c.name);
    printf("ID Number:");
    scanf("%d",&c.idNo);
    printf("Mobile Number:");
    scanf("%d",&c.mobileNo);
    printf("Gender:");
    scanf("%s",c.gender);
    c.accountNo = ((rand()%(upper - lower+1)+lower));
    printf("Your Account Number is:%d",c.accountNo);
    printf("\n"); 
      //fwrite(&c,sizeof(Customer),1,fp);
      fprintf(fp,"%s\t%d \t%d\t %s \t%d\t",c.name,c.idNo,c.mobileNo,c.gender,c.accountNo);
       fclose(fp);
       printf("Your details have been successfully saved:\n");
       printf("\n");
}
void Deposit()
{
   
    int n,deposit;
    Customer c, c1;
      c1.total =0;
      deposit = 0;
    
   FILE *fp;
    fp = fopen("/home/sammy/Downloads/File Project/Bank 1.c","r+w");
        if(fp != NULL)
        {
           fscanf(fp,"%s\t%d\t%d\t%s\t%d\t",c.name,&c.idNo,&c.mobileNo,c.gender,&c.accountNo);
           printf("For you to get a loan you must have invested with the bank for at least 6 months.\n");
            printf(" How many months do you want do deposit your Money.");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                
               printf("Enter amount for deposit for month %d: ",i+1);
               scanf("%d",&deposit);
                  c1.total += deposit;
           }
              printf("Enter your Account Number:");
                 scanf("%d",&c1.accountNo);
                 if(c1.accountNo == c.accountNo)
                 {
                     printf("You have successfully deposited %d",c1.total);
                     printf(" at ");
                       Time();
                       printf("\n");
                       printf(" Your account balance is %d",c1.total);
                 }else
                     printf("Check out your account number and try again.\n");
        }else
        {
            printf("Error in opening the file.\n");
            
        }
            c1.number = n; 
            fprintf(fp," %d\t%d\t ", c1.number,c1.total);
        
    fclose(fp);
    printf("\n");
    
}
void Withdraw()
{
    Customer c,c1,c2;
    c2.withdraw = 0;
    FILE *fp;
       fp =fopen("/home/sammy/Downloads/File Project/Bank 1.c","r+w");
       if(fp != NULL)
       {
           fscanf(fp,"%s\t%d\t%d\t%s\t%d\t%d\t%d\t",c.name,&c.idNo,&c.mobileNo,c.gender,&c.accountNo,&c1.number,&c1.total);
           
              printf("For withdraw of less than 10000, there is no transaction fee.\n");
              printf("1. 10001 upto 50000 transaction cost is 1000\n");
              printf("2. 50001 upto 100000 transaction cost is 1500\n");
              printf("3. 100001 upto 200000 transaction cost is 2000\n");
              printf("4. 200001 upto 500000 transaction cost is 4000\n");
              printf("5. Above 500000 transaction cost is 6000\n");
              
              
              printf(" Enter Amount for Withdrawal:");
              scanf("%d",&c2.Amount);
              printf("Enter your Account Number:");
              scanf("%d",&c2.accountNo);
        if(c2.Amount < c1.total)
        {
            if(c2.accountNo ==c.accountNo)
            {
              if(c2.Amount <= 10000 )
              {
                  c2.withdraw = c2.Amount;
                  printf("You have withdrwan %d", c2.withdraw);
                    printf(" at time ");
                     Time();
                     printf("\n");  
                     c2.balance = c1.total - c2.withdraw;
                     printf(" Your current balance is %d\n",c2.balance);
                     
                        
              }else if(c2.Amount > 10000 && c2.Amount <=50000 )
              {
                  c2.transcaction = 1000;
                  c2.withdraw = c2.Amount - c2.transcaction;
                  printf(" You have withdrwan %d",c2.withdraw);
                  printf(" at ");
                    Time();
                    printf(". Transaction cost is %d",c2.transcaction);
                    printf("\n");
                    c2.balance = c1.total - c2.Amount;
                    printf(" Your current balance is %d\n",c2.balance);
                  
              }else if(c2.Amount >50000 && c2.Amount <= 100000)
              {
                  c2.transcaction =1500;
                   c2.withdraw = c2.Amount - c2.transcaction;
                  printf(" You have withdrwan %d",c2.withdraw);
                  printf(" at ");
                    Time();
                    printf(". Transaction cost is %d",c2.transcaction);
                    printf("\n");
                    c2.balance = c2.balance = c1.total - c2.Amount;
                    printf(" Your current balance is %d\n",c2.balance);
                  
              }else if(c2.Amount > 100000 && c2.Amount <= 200000)
              {
                  c2.transcaction = 2000;
                  c2.withdraw = c2.Amount - c2.transcaction;
                  printf(" You have withdrwan %d",c2.withdraw);
                  printf(" at ");
                    Time();
                    printf(". Transaction cost is %d",c2.transcaction);
                    printf("\n");
                   c2.balance = c1.total - c2.Amount;
                    printf(" Your current balance is %d\n",c2.balance);
                  
              }else if(c2.Amount > 200000 && c2.Amount <= 500000)
              {
                  c2.transcaction = 4000;
                  c2.withdraw = c2.Amount - c2.transcaction;
                  printf(" You have withdrwan %d",c2.withdraw);
                  printf(" at ");
                    Time();
                    printf(". Transaction cost is %d",c2.transcaction);
                    printf("\n");
                    c2.balance = c1.total - c2.Amount;
                    printf(" Your current balance is %d\n",c2.balance);
                  
              }else if(c2.Amount > 500000)
              {
                  c2.transcaction = 6000;
                  c2.withdraw = c2.Amount - c2.transcaction;
                  printf(" You have withdrwan %d",c2.withdraw);
                  printf(" at ");
                    Time();
                    printf(". Transaction cost is %d",c2.transcaction);
                    printf("\n");
                    c2.balance = c1.total - c2.Amount;
                    printf(" Your current balance is %d\n",c2.balance);
              }
              
            }else
            {
                printf("Check out your Account Number and try again.\n");
                  exit(-1);
            }
              
              
       }else
       {
           printf("You cannot withdraw %d", c2.Amount);
            printf(" due to insufficient funds in the account.Try a lower amount.\n");
            exit(-1);
           
       }
       
       
    }else
     { 
        printf("Error in opening the file.\n"); 
         exit(-1);  
     }
            
            fprintf(fp," %d ",c2.withdraw,c2.balance);
       fclose(fp);
}

void Requestforlooan()
{
    Customer c,c1,c2,c3;
    c3.rloan = 0;
    FILE *fp;
     fp = fopen("/home/sammy/Downloads/File Project/Bank 1.c","r+a");
       fscanf(fp,"%s\t%d\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t",c.name,&c.idNo,&c.mobileNo,c.gender,&c.accountNo,&c1.number,&c1.total,&c2.withdraw,&c2.balance);
     if(fp != NULL)
     {    
       printf("For you to get a loan you must have invested with the bank for at least 6 months.\n");
        
          if(c1.number < 6)
          {
              printf(" You dont qualify for a loan.\n");
          }else 
          {
              printf("Loan of less than 10000, interest = 1.5%\n");
              printf("Loan of 10001 upto 50000, interest = 2.8%\n");
              printf("Loan of 50001 upto 200000, interest = 4.5%\n");
              printf("Loan of 200001 upto 350000, interest = 6%\n");
              printf("Loan of 350001 upto 500000, interest = 7.5%\n");
              printf("Loan of greater 500000, interest = 10%\n");
              
              printf(" Enter Amount for Loan:");
              scanf("%d",&c3.rloan);
              printf(" Enter Account Number:");
              scanf("%d",&c3.accountNo);
              
              if( c3.accountNo == c.accountNo)
              {
                 printf(" You have been successfully given a loan of %d",c3.rloan);
                 printf(" at ");
                  Time();
                 
              }else
              {
                  printf(" Check out your Account Number and try again.\n");
                   exit(-1);
              } 
              
              
          }
          
     }else 
     {
         printf(" Error in opening the file.\n");
         exit(-1);
     }
         fprintf(fp," %d ", c3.rloan);
      fclose(fp);
}
 void Payloan()
 {
     Customer c,c1,c2,c3,c4;
       FILE *fp;
           fp = fopen("/home/sammy/Downloads/File Project/Bank 1.c","r+a");
              if(fp != NULL)
              { 
                  fscanf(fp,"%s\t%d\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t",c.name,&c.idNo,&c.mobileNo,c.gender,&c.accountNo,&c1.number,&c1.total,&c2.withdraw,&c3.rloan,&c2.balance);
                  printf("Loan of less than 10000, interest = 1.5%\n");
                  printf("Loan of 10001 upto 50000, interest = 2.8%\n");
                  printf("Loan of 50001 upto 200000, interest = 4.5%\n");
                  printf("Loan of 200001 upto 350000, interest = 6%\n");
                  printf("Loan of 350001 upto 500000, interest = 7.5%\n");
                  printf("Loan of greater 500000, interest = 10%\n"); 
                  
                  printf(" %s",c.name);
                  printf(",you had requested for a loan of %d",c3.rloan);
                  //printf("\n");
                  
                   printf(" Pay for your loan.Enter Amount:");
                   scanf("%d",&c4.ploan);
                   
                   printf("Enter your Account Number:");
                   scanf("%d", &c4.accountNo);
                   if( c4.accountNo == c.accountNo)
                {
                    if(c1.total > c3.rloan)
                    {
                       if(c3.rloan <= 10000)
                       {
                           if(c4.ploan > c3.rloan)
                           {
                           c4.interest == 0.015;
                           c4.payloan = ((c3.rloan + (c4.interest * c3.rloan)));
                           printf(" You have successfully paid %d",c3.rloan);
                           printf(" at ");
                            Time();
                            c4.balance = c1.total- c4.payloan;
                            printf(" Your Account balance is %d\n",c4.balance);
                            printf(" at ");
                            Time();
                            
                           }else{
                               printf("Cannot pay %d due to insufficient Amount in the Account ",c3.rloan);
                               exit(-1);
                           }
                       }else if(c3.rloan >10000 && c3.rloan <=50000)
                       {
                           if(c4.ploan > c3.rloan)
                           {
                           c4.interest = 0.028;
                           c4.payloan = (c3.rloan + (c4.interest * c3.rloan));
                           printf(" You have successfully paid %d",c3.rloan);
                           printf(" at ");
                            Time();
                            c4.balance = c1.total - c4.payloan;
                            printf(" Your Account balance is %d\n",c4.balance);
                             printf(" at ");
                             Time();
                             
                           }else
                           {
                               printf(" Cannot pay %d due to insufficient amount in the account",c3.rloan);
                               exit(-1);
                           }
                       }else if(c3.rloan > 50000 && c3.rloan <=200000)
                       {
                           if(c4.ploan > c3.rloan)
                           {
                           c4.interest = 0.045;
                           c4.payloan = (c3.rloan + (c4.interest * c3.rloan));
                           printf(" You have successfully paid %d",c4.payloan);
                           printf(" at ");
                            Time();
                            c4.balance = c1.total - c4.payloan;
                            printf(" Your Account balance is %d ",c4.balance);
                            printf(" at ");
                            Time();
                            
                           }else
                           {
                               printf("Cannot pay %d due to insufficient amount in the account",c3.rloan);
                               exit(-1);
                           }
                       }else if (c3.rloan > 200000 && c3.rloan <=350000)
                       {
                           c4.interest = 0.06;
                           if(c4.ploan > c3.rloan)
                        {
                            c4.payloan = (c3.rloan + (c4.interest * c3.rloan));
                           printf(" You have successfully paid %d",c3.rloan);
                           printf(" at ");
                            Time();
                            c4.balance = c1.total - c4.payloan;
                            printf(" Your Account balance is %d\n",c4.balance);
                            printf(" at ");
                            Time();
                            
                           }else
                           {
                               printf("Cannot pay %d due to insufficient amount in the account ",c3.rloan);
                               exit(-1);
                           }
                           
                       }else if(c3.rloan > 350000 && c3.rloan <= 500000)
                       {
                           c4.interest= 0.075;
                        if(c4.ploan > c3.rloan)
                        {
                           c4.payloan = (c3.rloan + (c4.interest * c3.rloan));
                           printf(" You have successfully paid %d",c3.rloan);
                           printf(" at ");
                            Time();
                            c4.balance = c1.total - c4.payloan;
                            printf(" Your Account balance is %d\n",c4.balance);
                            
                        }else
                        {
                            printf("Amount must be greater than %d",c3.rloan);
                            exit(-1);
                        }
                           
                       }else if(c3.rloan > 500000)
                       {
                           c4.interest = 0.1;
                           if(c4.ploan > c3.rloan)
                           {
                           c4.payloan = c3.rloan + (c4.interest * c3.rloan);
                           printf(" You have successfully paid %d",c3.rloan);
                           printf(" at ");
                            Time();
                            c4.balance = c1.total - c4.payloan;
                            printf(" Your Account balance is %d\n",c4.balance);
                           
                       }else
                       {
                           printf("Cannot pay %d due to insufficient amount in the acount",c3.rloan);
                           exit(-1);
                       }
                       
                    }else
                    {
                        printf("Cannot pay loan due to insufficient funds in the account.\n");
                        exit(-1);
                    }
                       
                   }else
                   {
                       printf(" Check your  Account Number and try again.\n ");
                       exit(-1);
                   }
                       
                }   
              }else 
              {
                  printf("Error in opening the file.\n");
                     exit(-1);
              }
              
          fprintf(fp," %d ",c4.payloan);
         fclose(fp);
 }
 void Userinfo()
 {
     Customer c,c1,c2,c3,c4,c5;
     FILE *fp;
       fp = fopen("/home/sammy/Downloads/File Project/Bank 1.c","r");
       if(fp != NULL)
       {
        fscanf(fp,"%s\t%d\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t",c.name,&c.idNo,&c.mobileNo,c.gender,&c.accountNo,&c1.number,&c1.total,&c2.withdraw,&c3.rloan,&c4.payloan);
            printf("CUSTOMER DETAILIS\n");
           printf("----------------------------");
           printf("\nName: %s",c.name);
           printf("\nID Number: %d",c.idNo);
           printf("\nMobile Number: %d",c.mobileNo);
           printf("\nGender: %s",c.gender);
           printf("\nAccount Number: %d",c.accountNo);
           printf("\nNumber of months money deposited: %d",c1.number);
           printf("\nDeposited Amount: %d",c1.total);
           printf("\nWithdrawn Amount: %d",c2.withdraw);
           printf("\nRequested Loan: %d",c3.rloan);
            printf("\n");
       }else
       {
           printf(" Error in opening the file.\n");
             exit(-1);
       }
     fclose(fp);
 }

 //void PrintErrorMessage();

int main()
{
   int ch;
    do{
    printf("*****BANK MANAGEMENT SYSTEM MENU*****\n");
    printf("1.Sign In\n");
    printf("2.Deposit Cash\n");
    printf("3.Withdraw Cash\n");
    printf("4.Request For A Loan\n");
    printf("5.Pay Loan\n");
    printf("6.User Information\n");
    printf("0.Exit\n");
    
    printf("\n");
    
    printf("Please Select Your Option:");
    scanf("%d",&ch);
     switch(ch){
         case 1:
              Signin();
              break;
          case 2:
                Deposit();
                break;
            case 3:
                Withdraw();
                break;
            case 4:
                Requestforlooan();
                 break;
           case 5:
                Payloan();
               break;
            case 6:
                Userinfo();
                break;
            default:
              PrintErrorMessage();
              break; 
                  
     }

    }while(ch !=0 );
}

 void PrintErrorMessage(){
    printf("That option is currently unavailable");
    exit(-1);
}
 


 
 




