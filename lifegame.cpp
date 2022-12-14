#include <vector>   //vector
#include <cstdlib>  // rand
#include <iostream> // cout
#include <thread>   // thread
#include <chrono>   // chrono

struct table // tableストラクトの定義
{
  std::vector<std::vector<bool>> data;
  table(int N) //初期化・コンストラクタ（N*N配列）
  {
    for (int i = 0; i < N; i++)
    {
      data.emplace_back();
      for (int j = 0; j < N; j++)
      {
        data.at(i).push_back(rand() % 2);
      }
    }
  };

  table(std::string name)
  {
    if (name == "galaxy")
    {
      data = {
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
          {0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
          {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
          {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
          {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
          {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
          {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    }
    else if (name == "glider-gun")
    {
      data = {
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
          {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    }
  };

  int width() //メンバ関数定義
  {
    return data.at(0).size();
  }
  int height()
  {
    return data.size();
  }
  std::vector<bool> at(int y) //読み取り専用
  {
    return data.at(y);
  }
  void replace(int x, int y, bool val) //代入
  {
    data[y][x] = val;
    return;
  }
  bool is_same(table &data_n)
  {
    return data == data_n.data;
  }
};

bool at_cell(table &data, int x, int y) // dataの(x,y)のセルの状態を返す関数
{
  if (x < 0 || y < 0 || x >= data.width() || y >= data.height()) // dataのは範囲外ならFalse
  {
    return false;
  }
  else
  {
    return data.at(y).at(x);
  }
}

int count_surround(table &data, int x, int y) //周囲のセルの合計値を返す
{
  int asw = 0;
  for (int i = x - 1; i < x + 2; i++)
  {
    for (int j = y - 1; j < y + 2; j++)
    {
      asw += at_cell(data, i, j);
    }
  }
  return asw - at_cell(data, x, y);
}

bool dead_or_alive(table &data, int x, int y) //周囲のセルを探査し、生存しているセルの周囲が2か3生存ならtrue、それ以外はfalse、死んだセルの周囲が3つならtrue
{
  if (at_cell(data, x, y)) //セルが生存している場合
  {
    return count_surround(data, x, y) == 2 || count_surround(data, x, y) == 3 ? true : false;
  }
  else //セルが死んでいる場合
  {
    return count_surround(data, x, y) == 3 ? true : false;
  }
}

void print_table(table &data) //テーブルを表示する関数、元配列を参照
{
  std::system("clear");
  for (int i = 0; i < data.width() + 2; i++)
  {
    std::cout << "-";
  }
  std::cout << std::endl;
  for (int i = 0; i < data.height(); i++)
  {
    std::cout << "|";
    for (int j = 0; j < data.width(); j++)
    {
      data.at(i).at(j) ? std::cout << "■" : std::cout << " ";
    }
    std::cout << "|" << std::endl;
  }
  for (int i = 0; i < data.width() + 2; i++)
  {
    std::cout << "-";
  }
  std::cout << std::endl;
  return;
}

table next_gen(table &data) //次世代の盤面を作る、元配列をコピー
{
  table data_n = data;
  for (int y = 0; y < data.height(); y++)
  {
    for (int x = 0; x < data.width(); x++)
    {
      data_n.replace(x, y, dead_or_alive(data, x, y));
    }
  }
  return data_n;
}

int main()
{
  table t("galaxy");
  bool runnning = true;

  while (runnning)
  {
    print_table(t);
    table t_n = next_gen(t);
    t_n.is_same(t) ? runnning = false : t = t_n;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
