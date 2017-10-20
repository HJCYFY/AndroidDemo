package huajun.myapplicationaa;

import android.annotation.SuppressLint;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Environment;
import android.os.Looper;
import android.support.v4.util.LogWriter;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.util.LogPrinter;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private static final String TAG = "MainActivity";
    private String picsPath = Environment.getExternalStorageDirectory().getAbsolutePath()+"/DCIM/Camera/test.jpg";
    private String resultPath =Environment.getExternalStorageDirectory().getAbsolutePath()+"/DCIM/Camera/output.jpg";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.text);
        tv.setText(resultPath);
    }

    @SuppressLint("StaticFieldLeak")
    public void compress(final View view) {
        view.setClickable(false);

        File file = new File(picsPath);
        if(!file.exists()) {
            Toast.makeText(MainActivity.this, "找不到文件", Toast.LENGTH_SHORT)
                    .show();
            return;
        }
        nativeCompressBitmap(picsPath,resultPath);
        view.setClickable(true);
    }

    public native int nativeCompressBitmap(String souPath,String resultPath);
}
