void selectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int min_pos = i;
        for(int j = i + 1; j < n; j++){
            if (a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        swap(a[min_pos], a[i]);
    }
}
