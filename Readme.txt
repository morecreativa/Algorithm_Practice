KnowHow
1. $ git init = 폴더 경로를 init값으로 지정
2. $ git status = 폴더 파일 리스트 및 변경 상태 확인
3. $ git add 파일명  = commit할 파일 추가 [ .은 모든파일]
4. $ git commit -m "Push 메세지명" = PS붙여서 commit
5. $ git remote add origin [repository] = 저장소 origin으로 설정
6. $ git remote -v = 로컬 저장소 원격 저장소 연결
7. $ git push / pull origin master = origin에서 master로 설정된 것 push / pull
8. $ git stash = stash라는 곳에 임시 저장해놓고 다른 사람 commit 받을 수 있음
   (error: Your local changes to the following files would be overwritten by merge) 오류 시 사용

초기 설정 = 1 5

자기꺼 수정 후 올릴 때 = 3 4 7

다른사람꺼 수정된 것 받을 때 = 8 7

git꺼로 바뀜 = $ git pull --rebase origin master
                    $ git push origin master