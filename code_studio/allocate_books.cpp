/* Use the sqrt(x) technique */

bool isPossible(vector<int>& arr, int n, int m, int mid){
    int pageSum = 0;
    int studentCount = 1;
    for(int i = 0; i < n; i++)  {
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }   else{
            studentCount++;
            if(studentCount > m || arr[i] > mid)    {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    int start = 0;
    int end = 0;
    int ans = -1;

    // if the number of students is greater than
    // the total number of books
    // that means each student cannot recieve atleast one book
    if(m > n)   {
        return ans;
    }

    for(int i = 0; i < n; i++)  {
        end += arr[i];
    }

    int mid = start + (end - start) / 2;
    while(start <= end) {
        if(isPossible(arr, n, m, mid))  {
            ans = mid;
            end = mid - 1;
        }   else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}