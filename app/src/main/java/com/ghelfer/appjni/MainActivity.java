package com.ghelfer.appjni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        TextView tv1 = findViewById(R.id.sample_sum);
        tv1.setText("soma = " + sumValues(3, 4));

        TextView tv2 = findViewById(R.id.sample_conv);
        tv2.setText("Fahreinheit = " + getFahreinheit(12));

        TextView tv3 = findViewById(R.id.sample_sort);

        int [] a = {3,5,1,6,9,4};
        int [] sorted = getBubbleSort(a);
        String  res = "";
        for (int x=0; x < sorted.length;x++){
            res += sorted[x] + ", ";
        }

        tv3.setText("sorting = " + res);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native int sumValues(int a, int b);
    public native float getFahreinheit(float Celcius);
    public native int [] getBubbleSort( int [] values);
}
