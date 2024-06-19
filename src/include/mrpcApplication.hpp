
#pragma once
class mrpcApplication
{
private:
  mrpcApplication();
  mrpcApplication(const mrpcApplication &) = delete;
  mrpcApplication(mrpcApplication &&) = delete;

public:
  ~mrpcApplication();

  mrpcApplication *getMrpcApplicationInstance();

  static void Init(int argc, char **argv);
};
