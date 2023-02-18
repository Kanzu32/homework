package com.company;

import java.util.Random;

public class Main {
    public static int binary_search(int[] arr, int left, int right, int elem){
        int m = -1;
        if (elem <= arr[left])
            return left;
        if (elem >= arr[right])
            return right;
        while(left<=right){
            m = (left+right)/2;
            if (elem >= arr[m] && elem < arr[m + 1])
                return m + 1;
            else if(elem>arr[m]){
                left = m + 1;
            }else{
                right = m - 1;
            }
        }
        return m;
    }
    public static void binary_insert_sort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int low = 0;
            int high = i - 1;
            int mid = binary_search(arr, low, high, key);
            for (int j = i; j > mid && key<arr[j-1]; j--) {
                arr[j] = arr[j - 1];
                arr[j - 1] = key;
            }
        }
    }
    public static void insert_sort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int t = arr[i];
            int j = i;
            while (j > 0 && t < arr[j - 1]) {
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
                j--;
            }
        }
    }

    public static void merge(int[] res, int[] arr1, int[] arr2) {
        int arr1min = 0;
        int arr2min = 0;

        int resmin = 0;

        while (arr1.length > arr1min && arr2.length > arr2min) {
            if (arr1[arr1min] > arr2[arr2min]) {
                res[resmin] = arr2[arr2min];
                arr2min++;
            } else {
                res[resmin] = arr1[arr1min];
                arr1min++;
            }
            resmin++;
        }
        while (arr1min < arr1.length) {
            res[resmin] = arr1[arr1min];
            resmin++;
            arr1min++;
        }
        while (arr2min < arr2.length) {
            res[resmin] = arr2[arr2min];
            resmin++;
            arr2min++;
        }
    }

    public static void merge_sort(int[] arr) {
        if (arr.length < 2) {
            return;
        }
        int mid = arr.length / 2;
        int[] left = new int[mid];
        int[] right = new int[arr.length - mid];
        System.arraycopy(arr, 0, left, 0, mid);
        System.arraycopy(arr, mid, right, 0, arr.length - mid);
        merge_sort(left);
        merge_sort(right);
        merge(arr, left, right);
    }

    public static void main(String[] args) {
        Random r = new Random();
        for (int i = 5; i <= 35; i += 5) {
            int[] arr = new int[i];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = r.nextInt(100);
            }
            for (int t : arr) {
                System.out.print(t + " ");
            }
            System.out.println();
            double time = System.nanoTime()/1000.0;
            binary_insert_sort(arr);
            System.out.println(System.nanoTime()/1000.0 - time);
            for (int t : arr) {
                System.out.print(t + " ");
            }
            System.out.println();
        }
    }
}
