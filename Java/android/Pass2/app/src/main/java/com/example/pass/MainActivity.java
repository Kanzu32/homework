package com.example.pass;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.media.Image;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.google.android.material.textfield.TextInputEditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final Button button = (Button)findViewById(R.id.button);
        final EditText loginField = (EditText) findViewById(R.id.login);
        final EditText passwordField = (EditText) findViewById(R.id.password);
        final TextView resultField = (TextView) findViewById(R.id.result);
        final String passwordVal = "abc123";
        final String loginVal = "admin";

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (loginField.getText().toString().equals(loginVal) &&
                    passwordField.getText().toString().equals(passwordVal))
                {
                    resultField.setText("Верно");
                    resultField.setTextColor(Color.GREEN);
                } else {
                    resultField.setText("Вы ошиблись в логине или пароле");
                    resultField.setTextColor(Color.RED);
                }
                passwordField.setText("");
                loginField.setText("");
            }
        });
    }

}