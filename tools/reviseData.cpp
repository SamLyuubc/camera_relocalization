#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <string.h>
using namespace std;


string find_number(string input)
{
   string output;
   for(int i=0; i<input.length(); i++)
   {

        if(isdigit(input[i]))
        {
            output+=input[i];
        }
   }

   return output;
}




int main()
{
    FILE *fp;
    char buff[255];

    fp=fopen("/home/automationlab/catkin_ws/src/bagtodepth/TrainingData/rgb.txt", "r");
    assert(fp);
    vector<string> img_names;

    ofstream fout("/home/automationlab/catkin_ws/src/bagtodepth/TrainingData/revised_rgb.txt");

    while(!feof(fp))
    {
        char img_name[1024] ={NULL};

        fscanf(fp, "%s", img_name);

        img_names.push_back(img_name);
        //cout<<img_name<<endl;
    }

    vector<string> revised_img_names;

    for(int i=0; i<img_names.size(); i++)
    {
        //cout<<img_names[i]<<" "<<img_names[i].length()<<endl;
        if(img_names[i].length()!=11)
        {
            string num_img_name = find_number(img_names[i]);
            string revised_img_name = num_img_name+".0.png";
            revised_img_names.push_back(revised_img_name);
            cout<<revised_img_name<<endl;
        }

    }
}
