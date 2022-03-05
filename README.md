# **ZtoLL_Plot**
This is a place where I put the LLP project code. I'm using Ubuntu Linux WSL with a Windows host computer.
You can't run these code directly only if you have the root files.
## **Table of Contents**
*  ana : The Background generate code is put in here, most of code are write by C++ !!!
*  figure_output : background figure

## **Required Software**
*  **[CERN ROOT](https://root.cern/install/)**: An open-source data analysis framework used by high energy physics and others. You can follow the install document to install it.

## **Backgound Estermation(Fake Rate)**
* ## **Draw Code**
```
cd ana
```
The file name is already tell about what are they doing.
* ## **For fakerate**
The process is first run below command to produce fake rate plot
```
root ana/HT_fakerate.C and Top_fakerate.C 
```
and then run the following command to compare two physics process fake rate
```
root ana/compare_fake.C 
```

