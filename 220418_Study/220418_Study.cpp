/*
1. Version Control System
2. Computer Science Theory
3. Procedural Programming with C
4. Basic Game Programming
 
 배우는 순서

 순서1. 자료구조, 객체지향(이론), c# 유니티
 순서2. 객체지향, c++, 자료구조, c#, 유니티
 
 자료관리

 1. 원격 저장소를 만드는 명령어 -> git clone
 2. 원격 브랜치 : 원격 저장소를 추적하는 특수한 브랜치 (remote name, branch name)

 3. git fetch : 원격 저장소의 내용을 로컬에도 동기화
 - 로컬에 없는 커밋을 다운로드한다.
 - 원격 브랜치를 업데이트한다.
 4.git pull : git fetch 후 git merge 를 하는 두 명령어를 묶은 명령어

 버전관리 시스템
 로컬관리 : 내 컴퓨터에서 만 버전관리

중앙집중형 :서버에서만 버전관리

분산형 : 내컴퓨터+서버 관리  <-Git


Git은 스냅샷을 이용해서 버전관리를 진행한다.

-committed : 버전관리를 한 상태
-modifide 수정이 일어난 상태
-staged : 커밋하겠다고 한 상태

명령어

git commit 커밋하기
git branch 브랜치를 만드는 것
branch 특정 커밋에 대한 참조
-f 브랜치를 강제로 옮기는 것

git checkout 특정 버전(커밋)을 불러오는 것
-b 브랜치를 만들고 체크아웃까지 하는 것

git merge 서로 다른 두 커밋을 합쳐서 새로운 커밋을 생성하는 것
git rebase 커밋을 복사해 다른 커밋으로 이동시키는 것
-i 인터렉티브 리베이스
cherry-pick 원하는 커밋을 복사해서 붙어넣는 것

-상대참조
HEAD 현재 작업중인 버전
^캐럿 특정 커밋의 부모
^2 두번째 부모 
~(숫자) 특정 커밋으로부터 (숫자) 만큼 떨어진 부모

git tag 특정 커밋에 어떤 내용을 남기는 것(보통 버전을 남기는데에 사용한다.)
git clone 원격 저장소를 복사한다.
git fetch 원격 저장소의 내용을 로컬로 가져오는 것
로컬에 없는 커밋을 다운로드하고 원격 브랜치를 업데이트함
 원격 브랜치 원격 저장소의 브랜치를 추적하는 것
git pull git fetch + git merge
git push 로컬 저장소의 내용을 원격으로 보낸다.
원격에 없는 커밋을 업로드하고 원격 브랜치를 업데이트함








*/
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}