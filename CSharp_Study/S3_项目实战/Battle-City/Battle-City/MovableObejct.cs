using System.Drawing;

namespace Battle_City
{
    enum Direction
    {
        Up = 0,
        Down,
        Left,
        Right
    }

    abstract class MovableObejct : GameObject
    {
        public Direction Dir { get; set; }
        public double Speed
        {
          get => speed / BlockSize;
          protected set => speed = (int)(value * BlockSize);
        }

        public Bitmap[] imgArr;
        public bool isMoving;
        public int speed;

        public MovableObejct(int xx, int yy, double s)
        {
            X = xx + 1;
            Y = yy + 1;
            Speed = s;

            imgArr = new Bitmap[4];
            isMoving = false;
        }

        public GameObject Move(int xAdd, int yAdd)
        {
            Rectangle rect = GetCollisionRectangle();
            int x1 = rect.X + xAdd;
            int y1 = rect.Y + yAdd;

            GameObject retObj = GOM.IsBlock(this, x1, y1);

            if (null != retObj)
            {
                return retObj;
            }

            x += xAdd;
            y += yAdd;
            return retObj;
        }

        public override Bitmap GetImage()
        {
            if (isMoving)
            {
                Img = imgArr[(int)Dir];
            }
            Img.MakeTransparent(Color.Black);
            return Img;
        }

        public override void Draw()
        {
            Graphics g = Form1.graphics;
            g.DrawImage(GetImage(), x - Img.Width / 2, y - Img.Height / 2);
        }

        public override Rectangle GetCollisionRectangle()
        {
            return new Rectangle(x - Img.Width / 2, y - Img.Height / 2, Img.Width, Img.Height);
        }
    }
}
