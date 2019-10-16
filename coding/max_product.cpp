//给定一个长度为N的整数数组，只允许用乘法，不能用除法，
//计算任意（N-1）个数的组合乘积中最大的一组，并写出算法的时间复杂度。 
#include<iostream>
#include<vector>

int maxProduct(const std::vector<int>& n){
    std::vector<int> s(n.size());
    std::vector<int> t(n.size());
    //s[i] 为0~i-1元素的乘积 s[0]为边界条件
    s[0] = 1;
    for(int i = 1; i < n.size(); i++){
        s[i] = s[i-1] * n[i-1];
    }
    //t[i] 为i+1到n.size()-1的元素的乘积、t[n.size-1] =1为边界调节
    t[n.size() -1] = 1;
    for(int i = n.size() - 2 ; i >=0; i--){
        t[i] = t[i+1] * n[i+1];
    }
    int maxRes = 0x80000000;
    for(int i = 0; i < n.size(); i++){
        int nTemp = s[i] * t[i];//i之前的元素和i之后元素的乘积，即去掉当前i元素的乘积
        std::cout << nTemp << " ";
	    if (nTemp > maxRes)
	    {
	        maxRes = nTemp;
	    }
    }
    return maxRes;
}

int main(){
    int arr[6] = {1, 4, -2, 5, -3, 3};
    std::vector<int> v(arr, arr + 6);
    int res = maxProduct(v);
    std::cout << "max product : " << res << std::endl;
    return 0;
}