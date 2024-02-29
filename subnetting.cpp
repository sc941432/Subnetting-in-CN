#include<iostream>
#include<cmath>
using namespace std;

char class_find(int ipV4[])
{
    if(ipV4[0]>=0 && ipV4[0]<=127)
    {
        return 'A';
    }

    if(ipV4[0]>=128 && ipV4[0]<=191)
    {
        return 'B';
    }

    if(ipV4[0]>=192 && ipV4[0]<=223)
    {
        return 'C';
    }

    return 'N';
}

void find_subnets(int temp,int subnet,int reserved_bit,int ipV4[],int mask[] )
{
    //subnet is total no of required subnets
    // temp holds class name
    //reserved bit tell how many more bit we have to reserved so that we can form required subnets;
    
    int total_reserved_bit=0;
    int req_subnet=subnet;
    cout<<"*********************************Start**************************************************\n";
    cout<<"Subnet \t\t starting address\t\t end address\n";
     switch(temp)
    {
        case 'A':      
                    total_reserved_bit=8+reserved_bit;
                    if(req_subnet==pow(2,reserved_bit))
                    {
                        for(int i=0;i<req_subnet;i++)
                        {
                            cout<<i+1<<"th subnet";
                            int variable=i;
                          	int index=total_reserved_bit-1;

                            while(variable>0)
                            {
                            	int rem=variable%2;
                            	variable=variable/2;
                            	mask[index--]=rem;
                            }

                            for(int i=total_reserved_bit;i<32;i++)
                            {
                            	mask[i]=0;
                            }
                            int start=0;
                            int start1=0;

                            while(start<32)
                            {
                            	int sum=0;
                            	for(int i=0;i<8;i++)
                            	{
                            		sum=sum+mask[start++]*pow(2,7-i);
                            	}
                            	ipV4[start1++]=sum;
                            }
                            
                        
                           //cout<<"Starting from\n";
                           cout<<"\t";
                           for(int i=0;i<4;i++)
                           {
                           	cout<<ipV4[i];
                           	if(i!=3)
                           	{
                           		cout<<".";
                           	}
                           }
                           //cout<<endl;
                           cout<<"\t\t";
                           
                           for(int i=total_reserved_bit;i<32;i++)
                            {
                            	mask[i]=1;
                            }
                            
                            start=8;
                           start1=1;
                            while(start<32)
                            {
                            	int sum=0;
                            	for(int i=0;i<8;i++)
                            	{
                            		sum=sum+mask[start++]*pow(2,7-i);
                            	}
                            	ipV4[start1++]=sum;
                            }
                            
                            //cout<<"Ending will be\n";
                           for(int i=0;i<4;i++)
                           {
                           	cout<<ipV4[i];
                           	if(i!=3)
                           	{
                           		cout<<".";
                           	}
                           }
                           //cout<<endl;
                           
                           if(ipV4[3]==255)
                           {
                           	for(int i=24;i<32;i++)
                           	{
                           		mask[i]=0;
                           	}
                     
                 
                           }
                           
                           if(ipV4[2]==255)
                           {
                           	for(int i=16;i<24;i++)
                           	{
                           		mask[i]=0;
                           	}
                           }
                            
                           cout<<endl; 
                        }
                        cout<<"**************************The End**********************************************"<<endl;
                    }
                    break;
        
        case 'B':
                    total_reserved_bit=16+reserved_bit;
                  
                    if(req_subnet==pow(2,reserved_bit))
                    {
                        for(int i=0;i<req_subnet;i++)
                        {
                            cout<<i+1<<"th subnet";
                            int variable=i;
                          	int index=total_reserved_bit-1;
                            while(variable>0)
                            {
                            	int rem=variable%2;
                            	variable=variable/2;
                            	mask[index--]=rem;
                            }
                            for(int i=total_reserved_bit;i<32;i++)
                            {
                            	mask[i]=0;
                            }
                            int start=0;
                            int start1=0;
                            while(start<32)
                            {
                            	int sum=0;
                            	for(int i=0;i<8;i++)
                            	{
                            		sum=sum+mask[start++]*pow(2,7-i);
                            	}
                            	ipV4[start1++]=sum;
                            }
                            
                            
                           //cout<<"Starting from\n";
                           cout<<"\t";
                           for(int i=0;i<4;i++)
                           {
                           	cout<<ipV4[i];
                           	if(i!=3)
                           	{
                           		cout<<".";
                           	}
                           }
                           //cout<<endl;
                           
                           for(int i=total_reserved_bit;i<32;i++)
                            {
                            	mask[i]=1;
                            }
                            
                            start=16;
                           start1=2;
                            while(start<32)
                            {
                            	int sum=0;
                            	for(int i=0;i<8;i++)
                            	{
                            		sum=sum+mask[start++]*pow(2,7-i);
                            	}
                            	ipV4[start1++]=sum;
                            }
                            
                            //cout<<"Ending will be\n";
                            cout<<"\t\t";
                           for(int i=0;i<4;i++)
                           {
                           	cout<<ipV4[i];
                           	if(i!=3)
                           	{
                           		cout<<".";
                           	}
                           }
                           //cout<<endl;
                           
                           if(ipV4[3]==255)
                           {
                           	for(int i=24;i<32;i++)
                           	{
                           		mask[i]=0;
                           	}
                     
                 
                           }
                           
                          
                            cout<<endl;
                            
                        }
                    }
                    break;

        case 'C':
                    total_reserved_bit=24+reserved_bit;
                     if(req_subnet==pow(2,reserved_bit))
                    {
                        for(int i=0;i<req_subnet;i++)
                        {
                            cout<<i+1<<"th subnet";
                            int variable=i;
                          	int index=total_reserved_bit-1;
                            while(variable>0)
                            {
                            	int rem=variable%2;
                            	variable=variable/2;
                            	mask[index--]=rem;
                            }
                            for(int i=total_reserved_bit;i<32;i++)
                            {
                            	mask[i]=0;
                            }
                            int start=0;
                            int start1=0;
                            while(start<32)
                            {
                            	int sum=0;
                            	for(int i=0;i<8;i++)
                            	{
                            		sum=sum+mask[start++]*pow(2,7-i);
                            	}
                            	ipV4[start1++]=sum;
                            }
                            
                            
                           //cout<<"Starting from\n";
                           cout<<"\t";
                           for(int i=0;i<4;i++)
                           {
                           	cout<<ipV4[i];
                           	if(i!=3)
                           	{
                           		cout<<".";
                           	}
                           }
                           //cout<<endl;
                           
                           for(int i=total_reserved_bit;i<32;i++)
                            {
                            	mask[i]=1;
                            }
                            
                            start=24;
                           start1=3;
                            while(start<32)
                            {
                            	int sum=0;
                            	for(int i=0;i<8;i++)
                            	{
                            		sum=sum+mask[start++]*pow(2,7-i);
                            	}
                            	ipV4[start1++]=sum;
                            }
                            
                            //cout<<"Ending will be\n";
                            cout<<"\t\t";
                           for(int i=0;i<4;i++)
                           {
                           	cout<<ipV4[i];
                           	if(i!=3)
                           	{
                           		cout<<".";
                           	}
                           }
                           cout<<endl;
                           
                           if(ipV4[3]==255)
                           {
                           	for(int i=24;i<32;i++)
                           	{
                           		mask[i]=0;
                           	}
                     
                 
                           }
                           
                          
                           cout<<endl; 
                            
                        }
                    }
                    break;
    }

}

void mask_data(char temp,int mask[],int ipV4[])
{

    if(temp=='A')
                    {
                        
                            int var=ipV4[0];
                            int index=7;
                            int rem;
                            while(var>0)
                            {
                                rem=var%2;
                                var=var/2;
                                mask[index--]=rem;
                            
                            }
                            if(index>=0)
                            {
                                for(int i=index;i>=0;i--)
                                {
                                    mask[i]=0;
                                }
                            }

                        for(int i=8;i<32;i++)
                        {  
                            mask[i]=0;                      
                        }
                    }

                    if(temp=='B')
                    {
                       // cout<<"2^16-2"<<endl;
                            int var=ipV4[0];
                            int index=7;
                            int rem;
                            while(var>0)
                            {
                                rem=var%2;
                                var=var/2;
                                mask[index--]=rem;
                            
                            }
                            if(index>=0)
                            {
                                for(int i=index;i>=0;i--)
                                {
                                    mask[i]=0;
                                }
                            }

                            var=ipV4[1];
                            index=15;
                            while(var>0)
                            {
                                rem=var%2;
                                var=var/2;
                                mask[index--]=rem;
                            }

                            if(index>=7)
                            {
                                for(int i=index;i>=8;i--)
                                {
                                    mask[i]=0;
                                }
                            }

                        for(int i=16;i<32;i++)
                        {  
                            mask[i]=0;                      
                        }
                    }
                    if(temp=='C')
                    {
                        //cout<<"2^8-2"<<endl;
                        int var=ipV4[0];
                            int index=7;
                            int rem;
                            while(var>0)
                            {
                                rem=var%2;
                                var=var/2;
                                mask[index--]=rem;
                            
                            }
                            if(index>=0)
                            {
                                for(int i=index;i>=0;i--)
                                {
                                    mask[i]=0;
                                }
                            }
                            rem=0;
                            var=ipV4[1];
                            index=15;
                            while(var>0)
                            {
                                rem=var%2;
                                var=var/2;
                                mask[index--]=rem;
                            }

                            if(index>=7)
                            {
                                for(int i=index;i>7;i--)
                                {
                                    mask[i]=0;
                                }
                            }

                            var=ipV4[2];
                            index=23;
                            while(var>0)
                            {
                                rem=var%2;
                                var=var/2;
                                mask[index--]=rem;
                            }

                            if(index>=15)
                            {
                                for(int i=index;i>15;i--)
                                {
                                    mask[i]=0;
                                }
                            }

                        for(int i=24;i<32;i++)
                        {  
                            mask[i]=0;                      
                        }

                        
                    }

}

int main()
{
    int mask[32];
    int ipV4[4];
     
    cout<<"Enter your ip address\n";
    for(int i=0;i<4;i++)
    {
        cout<<"Enter "<<i+1<<" Octat value\n";
        cin>>ipV4[i];
    }

    int choice;
    cout<<"Enter your choice you want to find subnet by CIDR or by Class\n";
    cout<<"1).BY CLASS 2). BY CIDR\n";
    cin>>choice;
    char temp;
    int reserved_bit;
    int subnet;
    switch(choice)
    {
        case 1:
                    temp=class_find(ipV4);
                    cout<<"Your IP address is from class "<<temp<<endl;
                    cout<<"How many subnet do you want for total host=";
                    cin>>subnet;
                    reserved_bit=0;
                    mask_data(temp,mask,ipV4);

                    while(1)
                    {
                        if(pow(2,reserved_bit)==subnet || pow(2,reserved_bit)>subnet)
                        {
                            break;
                        }

                        else
                        {
                            reserved_bit++;
                        }
                    }
                    find_subnets(temp,subnet,reserved_bit,ipV4,mask);
                    break;

        case 2:
                int cidr;
                cout<<"Enter CIDR notation: greater then 8";
                cin>>cidr;
                cout<<endl;
                char cla;
                
                reserved_bit=0;
                if(cidr>8 && cidr<16)
                {
                    cla='A';
                    reserved_bit=cidr-8;
                    subnet=pow(2,reserved_bit);
                }

                if(cidr>16 && cidr<24)
                {
                    cla='B';
                    reserved_bit=cidr-16;
                    subnet=pow(2,reserved_bit);
                }
                if(cidr>24 && cidr<32)
                {
                    cla='C';
                    reserved_bit=cidr-24;
                    subnet=pow(2,reserved_bit);
                }
                mask_data(cla,mask,ipV4);
                find_subnets(cla,subnet,reserved_bit,ipV4,mask);
                break;
    }


    return 0;
}
