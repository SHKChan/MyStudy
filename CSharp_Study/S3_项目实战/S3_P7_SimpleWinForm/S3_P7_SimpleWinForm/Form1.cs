using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace S3_P7_SimpleWinForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //GDI,需要在窗体的Paint事件中触发
            Graphics g = CreateGraphics(); //创建GDI绘图对象
            Pen p = new Pen(Color.Black); //创建画笔
            g.DrawLine(p, 5, 5, 100, 100); //绘制直线

            g.DrawString("Hello, World", new Font("Arial", 20), new SolidBrush(Color.Red), new PointF(150,150)); //绘制字符串

            Bitmap bm = Properties.Resources.GameOver; //加载资源
            bm.MakeTransparent(Color.Black); //使某颜色透明
            g.DrawImage(bm, 0, 0);
        }
    }
}
