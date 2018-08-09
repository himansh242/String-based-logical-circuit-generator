#include <bits/stdc++.h>
#include <fstream>
//#include <Engine.h>
using namespace std;
#define MAXN 10005
#define pb push_back
int nt[MAXN];
vector<vector<int> > adj(MAXN),in(MAXN);
map<string,int> nti;
map<int,string> itn;
bool vis[MAXN];
vector<int> p,q;
set<int> se;
map< string, int > orig; 

void dfs(int x,int en,vector<int> v){
	vis[x]=1;
	int i;
	v.push_back(x);
	if(x==en){
		for(i=0;i<v.size();i++){
			cout<<v[i]<<" ";
			se.insert(v[i]);
		}
		cout<<endl;
	}
	for(i=0;i<adj[x].size();i++){
		if(!vis[adj[x][i]]) dfs(adj[x][i],en,v);
	}
	vis[x]=0;
}


int main(){
	//Engine *ep=engOpen(NULL);
	int strt[500],end[500];int tos1=0,tos2=0;
 map <string, int> :: iterator itr;
 int c=1; int i; 
	ofstream outt("new.m");
	string line,l,gate,node;
	 fstream file; //object of fstream class
    
   //opening file "sample.txt" in out(write) mode
   file.open("sample.txt",ios::out);
    
   if(!file)
   {
       cout<<"Error in creating file!!!"<<endl;
       return 0;
   }
    
   cout<<"File created successfully."<<endl;
   //write text into file
   string str;
   cout<<"enter 0 for closing input\n";
 int b=1;
   while(1)
   {getline(cin,str);
   string s1,s2,s3,s4;
     if(str=="0")
     break;
   	file<<str<<"\n";
   	s1=str[0];
		bool g=false;
	//	cout<<s1<<endl;
		for( i=4;i<=7;i++)
		{
			if(str[i]=='(')
			break;
			s2+=str[i];
			
		    }
		  //  cout<<s2<<endl;
		for(i=7;i<=9;i++){
		
		if(str[i]=='('||(str[i]>='A'&&str[i]<='Z')||str[i]==',')
		continue;
		else
		{
			s3+=str[i];
			break;
		}
		} //cout<<s3<<endl;
		for(i=str.length()-2;i>=str.length()-2;i--)
		{
			if(str[i-1]==',')
			{s4+=str[i];
			g=true;}
		}
	//	cout<<s1<<endl;
	//	cout<<s2<<endl;
	//	cout<<s3<<endl;
	//	cout<<s4<<endl;
	//	cout<<g<<endl;
		if ( orig.find(s1) == orig.end() ) 
               orig.insert(pair <string, int> (s1, c)),c++;
        if ( orig.find(s2) == orig.end() ) 
               orig.insert(pair <string, int> (s2, c)),c++;
        if ( orig.find(s3) == orig.end() ) 
               orig.insert(pair <string, int> (s3, c)),c++;
        if ( orig.find(s4) == orig.end()&&g) 
            orig.insert(pair <string, int> (s4, c)),c++;
         for(itr=orig.begin();itr!=orig.end();++itr)
	 {
			cout<<itr->first<<" "<<itr->second<<endl;
		   }      
        for(itr=orig.begin();itr!=orig.end();++itr)
        {
        	if(itr->first==s2)
        	{
        		strt[tos1]=itr->second;
        		tos1++;
			}
			if(itr->first==s1)
        	{
        		end[tos2]=itr->second;
        		tos2++;
			}
			
		}
		for(itr=orig.begin();itr!=orig.end();++itr)
        {
        	if(itr->first==s3)
        	{
        		strt[tos1]=itr->second;
        		tos1++;
			}
			if(itr->first==s2)
        	{
        		end[tos2]=itr->second;
        		tos2++;
			}
			
		}
		if(g)
		{  //cout<<"if met\n";
			for(itr=orig.begin();itr!=orig.end();++itr)
        {
        	if(itr->first==s4)
        	{
        		strt[tos1]=itr->second;
        		tos1++;
			}
			if(itr->first==s2)
        	{
        		end[tos2]=itr->second;
        		tos2++;
			}
			
		}
		}
	}
	
   //closing the file
   file.close();
   	cout<<"s = [ ";
   	outt<<"s = [ ";
		for(i=0;i<tos1;i++)
		{
			cout<<strt[i]<<" ";
			outt<<strt[i]<<" ";
		}
		cout<<"];\n";
		outt<<"];\n";
        cout<<"t = [ ";
         outt<<"t = [ ";
		for(i=0;i<tos2;i++)
		{
			cout<<end[i]<<" ";
			outt<<end[i]<<" ";
		}
		cout<<"];\n";
		outt<<"];\n";
        cout<<"G=digraph(s,t);\n";
         outt<<"G=digraph(s,t);\n";
        cout<<"h = plot(G,'Layout','force');\n";
        outt<<"h = plot(G,'Layout','force');\n";
        for(itr=orig.begin();itr!=orig.end();++itr)
        {
        	cout<<"labelnode(h,["<<itr->second<<"],"<<"'"<<itr->first<<"');\n";
        		outt<<"labelnode(h,["<<itr->second<<"],"<<"'"<<itr->first<<"');\n";
		}
		cout<<"highlight(h,[ ";
		outt<<"highlight(h,[ ";
		for(itr=orig.begin();itr!=orig.end();++itr)
		{
			if(itr->first!="AND"&&itr->first!="NOT"&&itr->first!="NAND"&&itr->first!="OR"&&itr->first!="NOR"&&itr->first!="BUFF")
            {cout<<itr->second<<" ";
         outt<<itr->second<<" ";   
        }
		}
		cout<<"],'NodeColor','g');\n";
		outt<<"],'NodeColor','g');\n";
		cout<<"highlight(h,[ ";
		outt<<"highlight(h,[ ";
		for(itr=orig.begin();itr!=orig.end();++itr)
		{
			if(itr->first=="AND"||itr->first=="NOT"||itr->first=="NAND"||itr->first=="OR"||itr->first=="NOR"||itr->first=="BUFF")
           { cout<<itr->second<<" ";
		   outt<<itr->second<<" ";
		   }
		}
		cout<<"],'NodeColor','magenta');\n";
		outt<<"],'NodeColor','magenta');\n";
		cout<<"h.ArrowSize=15;\n";
		outt<<"h.ArrowSize=15;\n";
		cout<<"h.MarkerSize=10;\n";
		outt<<"h.MarkerSize=10;\n";
	
	ofstream out("oup.m");
	int j,x,y,z;
	int idx=1;
	
	ifstream myfile ("sample.txt");
	if(myfile.is_open())
    while(getline(myfile,line)){
    	l="";
    	i=0;
    	while(line[i]!=' '&&i<line.size()){
    		l+=line[i++];
		}
		i+=3;
		if(nti.find(l)==nti.end()){
			z=idx;
			itn[idx]=l;
			nti[l]=idx;
			idx++;
		}
		else z=nti[l];
		gate="";
		while(line[i]!='('&&i<line.size()){
			gate+=line[i++];
		}
		i++;
		y=idx;
		itn[idx]=gate;
		if(gate=="DFF") nt[idx]=1;
		else if(gate=="NOT") nt[idx]=2;
		else if(gate=="AND") nt[idx]=3;
		else if(gate=="OR") nt[idx]=4;
		else if(gate=="NAND") nt[idx]=5;
		else if(gate=="NOR") nt[idx]=6;
		else if(gate=="BUFF") nt[idx]=6;
		idx++;
		adj[y].pb(z);
		in[z].pb(y);
		while(i<line.size()){
			node="";
			while(line[i]==' '&&i<line.size()) i++;
			while(line[i]!=')'&&line[i]!=','&&i<line.size()){
				node+=line[i++];
			}
			if(nti.find(node)==nti.end()){
				x=idx;
				itn[idx]=node;
				nti[node]=idx;
				idx++;
			}
			else x=nti[node];
			adj[x].pb(y);
			in[y].pb(x);
			i++;
		}
    }
	string s,e;
	cout<<"Input Source: ";
	cin>>s;
	cout<<"Input Destination: ";
	cin>>e;
	int st,en;
	st=nti[s],en=nti[e];
	vector<int> v;
	dfs(st,en,v);
	set<int> f;
	vector<int> g;
	vector<int> u;
	for(set<int>:: iterator it=se.begin();it!=se.end();it++){
		if((*it)==st) continue;
		for(i=0;i<in[*it].size();i++){
			p.pb(in[*it][i]);
			q.pb(*it);
			f.insert(*it);f.insert(in[*it][i]);
		}
	}
	cout<<"s = [ ";
	out<<"s = [ ";
	for(i=0;i<p.size();i++) {
	cout<<p[i]<<" ";
	out<<p[i]<<" ";}
	cout<<"];\n";
	cout<<"t = [ ";
		out<<"];\n";
	out<<"t = [ ";
	for(i=0;i<q.size();i++){
	cout<<q[i]<<" ";
	out<<q[i]<<" ";}
	cout<<"];\n";
	out<<"];\n";
	cout<<"G=digraph(s,t);\nh = plot(G,'Layout','force');\n";
	out<<"G=digraph(s,t);\nh = plot(G,'Layout','force');\n";
	for(set<int>:: iterator it=f.begin();it!=f.end();it++){
		cout<<"labelnode(h,["<<*it<<"],'";
		out<<"labelnode(h,["<<*it<<"],'";
		if(itn[*it]=="AND")
		{cout<<itn[*it]<<" Z=XY ";
		 out<<itn[*it]<<" Z=XY ";
	    }
	    else	if(itn[*it]=="OR")
		{cout<<itn[*it]<<" Z=X+Y ";
		 out<<itn[*it]<<" Z=X+Y ";
	    }
	    else	if(itn[*it]=="NOT")
		{cout<<itn[*it]<<" Z=z ";
		 out<<itn[*it]<<" Z=z ";
	    }
	    else	if(itn[*it]=="NAND")
		{cout<<itn[*it]<<" Z=xy ";
		 out<<itn[*it]<<" Z=xy' ";
	    }
	    else	if(itn[*it]=="NOR")
		{cout<<itn[*it]<<" Z=Xy+Yx ";
		 out<<itn[*it]<<" Z=Xy+Yx ";
	    }
	    else	if(itn[*it]=="BUFF")
		{cout<<itn[*it]<<" Z=Z ";
		 out<<itn[*it]<<" Z=Z ";
	    }
	    else
		{
		cout<<itn[*it];
		out<<itn[*it];
			}	
		//cout<<itn[*it];	
		cout<<"');\n";
		
			
		out<<"');\n";
		if(nt[*it]==0) g.pb(*it); 
		else u.pb(*it);
	}
	cout<<"highlight(h,[ ";
	out<<"highlight(h,[ ";
	for(i=0;i<g.size();i++) {
	cout<<g[i]<<" ";
	out<<g[i]<<" ";}
	cout<<"],'NodeColor','g');\n";
	out<<"],'NodeColor','g');\n";
	cout<<"highlight(h,[ ";
	out<<"highlight(h,[ ";
	for(i=0;i<u.size();i++)
	{
		cout<<u[i]<<" ";
		out<<u[i]<<" ";
	}
	cout<<"],'NodeColor','magenta');\n";
	out<<"],'NodeColor','magenta');\n";
	//cout<<idx<<endl;
	cout<<"highlight(h,[ "<<st<<" "<<en<<" ], 'NodeColor','black');\nh.ArrowSize=15;\nh.MarkerSize=10;\n";
	out<<"highlight(h,[ "<<st<<" "<<en<<" ], 'NodeColor','black');\nh.ArrowSize=15;\nh.MarkerSize=10;\n";
	return 0;
}
