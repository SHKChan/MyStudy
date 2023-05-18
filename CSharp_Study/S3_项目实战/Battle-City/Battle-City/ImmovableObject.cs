using Battle_City.Properties;
using System;
using System.Drawing;

namespace Battle_City
{
    class ImmovableObject : GameObject
    {
        public ImmovableObject(int x, int y, ObjType t)
        {
            X = x;
            Y = y;

            switch (t)
            {
                case ObjType.Brick:
                    Img = Resources.Wall;
                    T = ObjType.Brick;
                    break;
                case ObjType.Steel:
                    T = ObjType.Steel;
                    Img = Resources.Steel;
                    break;
                case ObjType.Boss:
                    Img = Resources.Boss;
                    T = ObjType.Boss;
                    break;
                default:
                    Img = Resources.Wall;
                    T = ObjType.Brick;
                    break;
            }
        }
        public override Bitmap GetImage()
        {
            return Img;
        }

        public override void Draw()
        {
            Graphics g = Form1.graphics;
            g.DrawImage(GetImage(), x, y);
        }

        public override Rectangle GetCollisionRectangle()
        {
            return new Rectangle(x, y, Img.Width, Img.Height);
        }

        public override void Update()
        {
            Draw();
        }
    }
}
