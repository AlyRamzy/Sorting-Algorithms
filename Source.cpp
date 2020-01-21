#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void printVector(vector<int>x) {
	cout << endl ;
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << "\t";
	}
	cout << endl;
}
void insertionSort(vector<int>&x,int l,int h) {
	for (int i = l+1; i < h; i++) {
		int key = x[i];
		int j = i - 1;
		while (j >= l && x[j] > key) {
			x[j + 1] = x[j];
			j = j - 1;

		}
		x[j + 1] = key;
	}
}
void merge(vector<int>&x, int p, int q, int r) {
	int n1, n2;
	n1 = q - p + 1;
	n2 = r - q;
	vector<int> L, R;
	for (int i = 0; i < n1; i++) {
		L.push_back(x[p + i ]);

	}
	for (int i = 0; i < n2; i++) {
		R.push_back(x[q + i+1]);
	}
	L.push_back(1e10);
	R.push_back(1e10);
	int i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			x[k] = L[i];
			i++;
		}
		else {
			x[k] = R[j];
			j++;
		}
	}


}
void mergeSort(vector<int>&x, int p, int r) {
	if (p < r) {
		int q = floor((p + r) / 2);
		mergeSort(x, p, q);
		mergeSort(x, q + 1, r);
		merge(x, p, q, r);
	}
}
int partition(vector<int>&x, int p, int r) {
	int key = x[r];
	int i = p - 1;
	for (int j = p; j < r ; j++) {
		if (x[j] <= key) {
			i++;
			int temp = x[i];
			x[i] = x[j];
			x[j] = temp;
		}
	}
	int temp = x[i + 1];
	x[i + 1] = x[r];
	x[r] = temp;
	return i + 1;

}
void quickSort(vector<int>&x, int p, int r) {
	if (p < r) {
		int q = partition(x, p, r);
		quickSort(x, p, q - 1);
		quickSort(x, q + 1, r);

	}
}
void selectionSort(vector<int>&x) {
	for (int i = 0; i < x.size(); i++) {
		int minindex = i;
		for (int j = i; j < x.size(); j++) {
			if (x[j] < x[minindex]) {
				minindex = j;
			}

		}
		int temp = x[minindex];
		x[minindex] = x[i];
		x[i] = temp;

	}
}
void hypirdSort(vector<int>&x, int p, int r) {


		if ((r - p+1) <= 100) {
			insertionSort(x, p, r+1);
		

		}
		else {
				int q = floor((p + r) / 2);
		hypirdSort(x, p, q);
		hypirdSort(x, q + 1, r);
		merge(x, p, q, r);
			
			
		
		}
	
}

int main(int argc,char*  argv[]) {
	if(argc!=5){
		cout<<"WRONG FORMAT COMMAND , PLEASE FOLLOW THIS COMMAND :\n ./output 1 data.txt sorted_data.txt running_time.txt"<<endl;
		return 0;
	}
	string inputFile,outputFile,sortingNumber,runningTime;
	sortingNumber=argv[1];
	inputFile=argv[2];
	outputFile=argv[3];
	runningTime=argv[4];
	freopen(argv[2],"r",stdin);
	int nu;
	vector<int> x;
	clock_t begin, end;
	double t1 = 0.0;
	while(cin>>nu){
		x.push_back(nu);
	}

	begin = clock();
	if(sortingNumber=="0"){
		cout<<"Selection Sort";
		selectionSort(x);

	}
	else if(sortingNumber=="1"){
		cout<<"Insertion Sort";
		insertionSort(x,0,x.size());

	}
	else if(sortingNumber=="2"){
		cout<<"Merge Sort";
		mergeSort(x,0,x.size()-1);


	}
	else if(sortingNumber=="3"){
		cout<<"Quick Sort";
		quickSort(x,0,x.size()-1);

	}
	else if(sortingNumber=="4"){
		cout<<"Hybrid Sort";
		hypirdSort(x,0,x.size()-1);

	}
	cout<<endl;
	end = clock();
	cout<<x.size()<<"\t UN_SORTED :  ";
	t1 += (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<t1*1000<<endl;
	t1=0.0;
	begin=clock();
	if(sortingNumber=="0"){
		
		selectionSort(x);

	}
	else if(sortingNumber=="1"){
		
		insertionSort(x,0,x.size());

	}
	else if(sortingNumber=="2"){
		
		mergeSort(x,0,x.size()-1);


	}
	else if(sortingNumber=="3"){
	
		quickSort(x,0,x.size()-1);

	}
	else if(sortingNumber=="4"){
		
		hypirdSort(x,0,x.size()-1);

	}
	end=clock();
	t1 += (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<x.size()<<"\t SORTED :  ";
	cout<<t1*1000<<endl;
	freopen(argv[3],"w",stdout);

	printVector(x);








	
	return 0;
}