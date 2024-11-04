int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Wrong input\n";
    return 1;
  }
  if (left >= right || left < -1 || right > 1)
  {
    std::cerr << "Wrong input\n";
    return 1;
  }
}
