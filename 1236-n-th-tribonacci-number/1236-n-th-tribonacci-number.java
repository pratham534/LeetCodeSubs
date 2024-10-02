class Solution {
    public int tribonacci(int n) {
        ArrayList<Integer> arr = new ArrayList<Integer>(n+1);
        arr.add(0,0);
        arr.add(1,1);
        arr.add(2,1);
        for(int i=3;i<=n;i++){
            int sum3 = arr.get(i-1)+arr.get(i-2)+arr.get(i-3);
            arr.add(i, sum3);
        }
        return arr.get(n);
    }
}