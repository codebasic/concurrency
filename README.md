# concurrency

## 요구사항

1. C++11을 지원하는 컴파일러 (예: gcc, Visual Studio 2015)
2.	C++ 문법 강조를 지원하는 텍스트 편집기 또는 IDE

### 멀티플랫폼 gcc 활용

Docker gcc

1. Docker 설치 (https://www.docker.com)
2. gcc Docker image 설치 (https://hub.docker.com/_/gcc/)

    $ docker pull gcc
    
3. Docker 빌드/실행  

    $ python docker_run.py build *g++ options*
    
    $ python docker_run.py run *path*
