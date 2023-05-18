using System;
using System.Drawing;
using System.Windows.Forms;

namespace Battle_City
{
    public partial class Form1 : Form
    {
        // 双缓冲技术防止闪烁
        private Graphics G; // 再在窗体上绘制位图
        private Bitmap bitmap; // 先绘制在位图上
        public static Graphics graphics;
        public static Size Sz;
        private GameObjectManager GOM;
        public static Timer timer;

        public Form1()
        {
            Sz = new Size(390, 420);
            InitializeComponent();
            StartPosition = FormStartPosition.CenterScreen;
            GOM = new GameObjectManager();

            G = CreateGraphics();
            bitmap = new Bitmap(ClientSize.Width, ClientSize.Height);
            graphics = Graphics.FromImage(bitmap);

            GOM.Ini();
            GOM.graphics = graphics;

            // Set up the timer to update the game
            timer = new Timer();
            timer.Interval = 16;
            timer.Tick += UpdateGame;
            timer.Start();

            // Set up the form to handle keyboard input
            KeyPreview = true;
            KeyDown += GOM.OnKeyDown;
            KeyUp += GOM.OnKeyUp;
        }

        private void UpdateGame(object sender, EventArgs e)
        {
            // Update the game objects
            graphics.Clear(Color.Black);
            GOM.Update();

            // Redraw the form
            G.DrawImage(bitmap, 0, 0);
        }
    }
}
