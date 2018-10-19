package me.oogh.demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private DisplayView mDisplayView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
    }

    private void initView() {
        mDisplayView = findViewById(R.id.dv_surface);
        findViewById(R.id.btn_start).setOnClickListener(v->{
            mDisplayView.loadImage("/sdcard/out.jpg");
        });

    }

}
