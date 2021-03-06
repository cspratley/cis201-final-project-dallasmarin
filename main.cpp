/**
 * File:Final Project
 * Developer: Dalles Marin
 * Email: dallasmarin80@icloud.com
 * Description: Program is a concordance generator for the first chapter of Alice in wonderland.
 */

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<ctype.h>
#include<sstream>

int main()
{
    char file[20];

    //int line[100][2];
    
    int i=0,j=0,k=0;
    
    double line =0;

    std::string lines[1000];
    std::string word;
    std::string concord[1000];

    int count [1000]={0};
    int idx=0;

    std::cout << "Enter the text file name: " << std::endl;

    //read file name
    std::cin.get(file,100);
    std::ifstream ifs;

    //open text file
    ifs.open("text.txt");
    if(!ifs.is_open())
    {
        std::cout<< "Unable to open file: " << std::endl;
        return 0;
    }

    std::string w;//temporary string

    //read all lines
    while(ifs.good())
    {
        std::getline(ifs,word);//read line by line

        //removing punctuations and converting upper case letters to lower case
        for(int i=0;i<word.length();i++)
        {
            if(!isalpha(word.at(i)))
            {
                if(word.at(i)!=' ')
                    for(int j=i;j<word.length()-1;j++)
                    {
                        word.at(j)=word.at(j+1);
                    }
                if(i==word.length()-1)
                    word.at(i)=' ';
            }
        }

        std::istringstream iss(word);

        while(iss>>w) //read each word in each line
        {
            bool flag=false;

            int matchedAt=-1;
            for(int k=0;k<idx;k++)
            {
                if(concord[k]==w)
                {
                    flag=true;
                    matchedAt=k;
                }
            }

            if(flag!=true)
            {
                concord[idx] = w;
                count[idx] = 1;

                std::stringstream num;
                num<< line+1;
                lines[idx] = num.str();
                idx++;
            }

            else
            {
                count[matchedAt]++;
                
                std::stringstream numb;

                numb<<line+1;
                lines[matchedAt]=lines[matchedAt]+"," +numb.str();
            }
        }
        line=line+1;
    }
    //print concord

    std::cout<<std::left<<std::setw(15)<<"Word"<<std::setw(3)<<" : " << "count" << std::setw(3) << " : " << "Occurences" << std::endl;
    
    std::cout<<"------------------------------------------------------------------------------------"<<std::endl;

    for(int l=0;l<idx;l++)

        std::cout<<std::left<<std::setw(15)<<concord[l]<<std::setw(5)<<" : "<<count[l]<<std::setw(3)<<" : "<<lines[l]<<std::endl;

   

    return 0;
}

