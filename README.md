# 이것이 Bit Mask다
1. n개의 1만들기
int a=(1<<n)-1;

2. n번째를 1로 세팅
int a= a | (1<<n);

3. n번째가 1인지 검사
if(a & (1<<n) )

4. n번째 0으로 세팅
a = a & (1 << n ) ;

5. n번째 원소를 toggle
a = a ^ ( 1<<n );

6. 1의 갯수 세기
(1) Recursive
int bitCount ( int x ) {
   if(x==0) return 0;
   return x%2 + bitCount(x/2);
}

(2) Linear 신기해서 적어봄.
int bitCount ( int x ) {
   int c;
   int v=n;
   for ( c = 0; v; c++ )  v &= v-1;
   return c;
}

(2-1) Linear2 -> 쉽긴 쉽네
int bitCount ( int n ) {
   int x=0;
   while ( n ) {
      x+= ( n & 1 );
      n >>= 1;
   }
   return x;
}

7. 

# GitHub KnowHow
- 1. $ git init = 폴더 경로를 init값으로 지정
- 2. $ git status = 폴더 파일 리스트 및 변경 상태 확인
- 3. $ git add 파일명  = commit할 파일 추가 [ .은 모든파일]
- 4. $ git commit -m "Push 메세지명" = PS붙여서 commit
- 5. $ git remote add origin [repository] = 저장소 origin으로 설정
- 6. $ git remote -v = 로컬 저장소 원격 저장소 연결
- 7. $ git push / pull origin master = origin에서 master로 설정된 것 push / pull
- 8. $ git stash = stash라는 곳에 임시 저장해놓고 다른 사람 commit 받을 수 있음
   (error: Your local changes to the following files would be overwritten by merge) 오류 시 사용

초기 설정 = 1 5

자기꺼 수정 후 올릴 때 = 3 4 7

다른사람꺼 수정된 것 받을 때 = 8 7

git꺼로 바뀜 = $ git pull --rebase origin master
                    $ git push origin master


[cmd , powershell 명령어]
1. doskey ls= dir -> ls 명령어 사용 가능
2. 텍스트 파일 비교 code --diff FILE1 FILE2
3. 파일 빌드 -> g++ FILE1 -o a.exe
