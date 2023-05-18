using Battle_City.Properties;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Media;
using System.Windows.Forms;

namespace Battle_City
{
    enum ObjType
    {
        Empty = 0,
        Brick,
        Steel,
        Boss,
        Player,
        NpcSlow,
        NpcQuick,
        NpcGray,
        NpcGreen,
        NpcYellow,
        Bullet
    }

    class GameObjectManager : Object
    {
        private List<ImmovableObject> WallList;
        private List<MovableObejct> TankList;
        private List<Bullet> BulletList;
        private TankPlayer player;
        private int width;
        private int height;
        private bool isGameOver;
        private int gameDuration; // Time duration to win the game
        private int timeElapsed;
        private SoundPlayer startSound;
        public Graphics graphics;
        private Random random;

        public GameObjectManager()
        {
            WallList = new List<ImmovableObject>();
            TankList = new List<MovableObejct>();
            BulletList = new List<Bullet>();
            GameObject.BlockSize = 15;
            GameObject.GOM = this;
            width = Form1.Sz.Width;
            height = Form1.Sz.Height;
            isGameOver = false;
            gameDuration = 3 * 60 * 1000;
            timeElapsed = 0;
            startSound = new SoundPlayer(Resources.start);
            random = new Random();
        }

        public void Ini()
        {
            //top wall
            CreateWall(2, 2, 4, 11, ObjType.Brick);
            CreateWall(6, 2, 8, 11, ObjType.Brick);
            CreateWall(10, 2, 12, 9, ObjType.Brick);
            CreateWall(14, 2, 16, 9, ObjType.Brick);
            CreateWall(18, 2, 20, 11, ObjType.Brick);
            CreateWall(22, 2, 24, 11, ObjType.Brick);

            //bottom wall
            CreateWall(2, 17, 4, 26, ObjType.Brick);
            CreateWall(6, 17, 8, 26, ObjType.Brick);
            CreateWall(10, 15, 12, 22, ObjType.Brick);
            CreateWall(14, 15, 16, 22, ObjType.Brick);
            CreateWall(18, 17, 20, 26, ObjType.Brick);
            CreateWall(22, 17, 24, 26, ObjType.Brick);

            //middle wall
            CreateWall(4, 13, 8, 15, ObjType.Brick);
            CreateWall(18, 13, 22, 15, ObjType.Brick);
            CreateWall(10, 11, 12, 13, ObjType.Brick);
            CreateWall(14, 11, 16, 13, ObjType.Brick);
            CreateWall(12, 16, 14, 18, ObjType.Brick);

            //steel
            CreateWall(0, 14, 2, 15, ObjType.Steel);
            CreateWall(24, 14, 26, 15, ObjType.Steel);
            CreateWall(12, 4, 14, 6, ObjType.Steel);
            CreateWall(12, 18, 14, 20, ObjType.Steel);

            //boss
            CreateWall(11, 25, 15, 26, ObjType.Brick);
            CreateWall(11, 26, 12, 28, ObjType.Brick);
            CreateWall(14, 26, 15, 28, ObjType.Brick);
            CreateWall(12, 26, 13, 27, ObjType.Boss);

            //Tank
            player = (TankPlayer)CreateTank(8, 26, 0.15, ObjType.Player);
            CreateTank(0, 0, 0.10, ObjType.NpcYellow);
            CreateTank(24, 0, 0.15, ObjType.NpcGray);
            //CreateTank(0, 26, 0.15, ObjType.NpcGreen);
            //CreateTank(24, 26, 0.15, ObjType.NpcGreen);
            //CreateTank(14, 13, 0.2, ObjType.NpcQuick);

            startSound.Play();
        }

        internal void RemoveObj(GameObject obj)
        {
            if (obj is ImmovableObject)
            {
                if (ObjType.Boss == obj.T)
                {
                    isGameOver = true;
                }
                if (ObjType.Steel !=  obj.T)
                {
                    WallList.Remove((ImmovableObject)obj);
                }
            }

            if (obj is Tank)
            {
                if (ObjType.Player == obj.T)
                {
                    isGameOver = true;
                }
                TankList.Remove((Tank)obj);
            }
            
            if (obj is Bullet)
            {
                BulletList.Remove((Bullet)obj);
            }
        }

        private void CreateWall(int r1, int c1, int r2, int c2, ObjType type)
        {
            for (int x = r1; x < r2; x ++)
            {
                for (int y = c1; y < c2; y ++)
                {
                    WallList.Add(new ImmovableObject(x, y, type));
                }
            }
        }

        private MovableObejct CreateTank(int r1, int c1, double speed, ObjType type)
        {
            MovableObejct tank;
            switch (type)
            {
                case ObjType.Player:
                    tank = new TankPlayer(r1, c1, speed);
                    break;
                default:
                    tank = new TankNpc(r1, c1, speed, type);
                    break;
            }
            TankList.Add(tank);
            return tank;
        }

        public void CreateBullet(Bullet bullet)
        {
            BulletList.Add(bullet);
        }

        public void GameOver()
        {
            graphics.DrawImage(Resources.GameOver, 0, 0);
        }

        public void GameWin()
        {
            // Create a new Font object
            Font font = new Font("Arial", 16);

            // Set the color of the font
            SolidBrush brush = new SolidBrush(Color.White);

            // Draw the text on the form
            graphics.DrawString("You Win!", font, brush, new PointF(width/2, height/2));
        }

        public void RandomCreateTank()
        {
            if (TankList.Count > 3)
            {
                return;
            }
            TankNpc t = null;
            GameObject ret = null;
            int X;
            int Y;
            ObjType T;
            double S;
            do
            {
                X = random.Next(0, 24);
                Y = random.Next(0, 24);
                T = (ObjType)(random.Next(5, 9));
                S = 0.15;
                switch (T)
                {
                    case ObjType.NpcSlow:
                        S = 0.1;
                        break;
                    case ObjType.NpcQuick:
                        S = 0.2;
                        break;
                }
                t = new TankNpc(X, Y, S, T);
                ret = IsBlock(t, t.x - GameObject.BlockSize, t.y - GameObject.BlockSize);
            } while (null != ret);
            CreateTank(X, Y, S, T);
        }

        public void Update()
        {
            if (gameDuration < timeElapsed)
            {
                GameWin();
                return;
            }
            if (isGameOver)
            {
                GameOver();
                return;
            }

            foreach (var wall in WallList)
            {
                wall.Update();
            }

            for (int i = 0; i < TankList.Count; i++)
            {
                TankList[i].Update();
            }

            timeElapsed += Form1.timer.Interval;

            RandomCreateTank();
        }

        public GameObject IsBlock(GameObject obj, int x1, int y1)
        {
            Rectangle objRect = obj.GetCollisionRectangle();
            objRect.X = x1;
            objRect.Y = y1;
            int x2 = objRect.Right;
            int y2 = objRect.Bottom;
            if (x1 < 0 || y1 < 0 || x2 >= width || y2 >= height)
            {
                return obj;
            }

            foreach (var wall in WallList)
            {
                Rectangle wallRect = wall.GetCollisionRectangle();
                if (objRect.IntersectsWith(wallRect))
                {
                    // Handle collision between tank and wall
                    return wall;
                }
            }
            
            for (int i = 0; i < TankList.Count; i++)
            {
                if (TankList[i] == obj)
                {
                    continue;
                }
                Rectangle tankRect = TankList[i].GetCollisionRectangle();
                if (objRect.IntersectsWith(tankRect))
                {
                    // Handle collision between tank and tank
                    return TankList[i];
                }
            }

            for (int i = 0; i < BulletList.Count; i++)
            {
                if (BulletList[i] == obj)
                {
                    continue;
                }
                Rectangle bulletRect = BulletList[i].GetCollisionRectangle();
                if (objRect.IntersectsWith(bulletRect))
                {
                    // Handle collision between tank and tank
                    return BulletList[i];
                }
            }

            return null;
        }

        public void OnKeyDown(object sender, KeyEventArgs e)
        {
            player.OnKeyDown(e);
        }

        public void OnKeyUp(object sender, KeyEventArgs e)
        {
            player.OnKeyUp(e);
        }
    }
}
