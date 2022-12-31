# Simple Shell

<html>

<head>
<meta http-equiv=Content-Type content="text/html; charset=utf-8">
<meta name=Generator content="Microsoft Word 15 (filtered)">

</head>

<body lang=ko-Kore-KR link="#0563C1" vlink="#954F72" style='word-wrap:break-word'>

<div class=WordSection1>

<p class=MsoNormal><span lang=EN-US style='font-size:24.0pt'>&nbsp;</span></p>

<h2><a name="_Toc115530923"><b><span lang=EN-US style='font-size:14.0pt'>Shell</span></b></a></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>Shell(</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>쉘</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>)</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>은 사용자가 운영체제와 직접적으로 상호작용하는 것을 가능케 하는 작은 프로그램이다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>사용자는 쉘을 통해 운영체제가 지원하는 명령어 혹은 프로그램을 실행할 수
있다</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자가 쉘에 문자열로 이루어진 입력을 넣으면</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>쉘은 해당 입력에 맞게 동작하며</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>그동안 사용자로부터 입력을 받는 것을 중단한다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>쉘이 사용자의 입력을 올바르게 수행하려면 커널에 접근해야 하는데</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이때 쉘은 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>System Call(</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>시스템 호출</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>)</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을 사용한다</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템 호출이란 커널 모드에서만 가능한
일을 수행할 수 있도록 커널에 처리를 요청하고</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리 결과를 커널로부터 받아오는 것이다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>사용자 입력에 해당하는 동작이 시스템 호출을 거쳐 완료되면</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>쉘은 다시 사용자로부터 입력을 기다리게 된다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>본 과제는 시스템 호출 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>API</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>를 사용하여 간단한 쉘을 제작하는 것이 목표이다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>여러가지 시스템 호출 중 본 과제에 사용되는 호출들을 알아보자</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<h2><a name="_Toc115530924"><b><span lang=EN-US style='font-size:14.0pt'>System
Call</span></b></a></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc115530925"><b><span
lang=EN-US>fork()</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US>fork()</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>새로운</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>만들</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>호출이다</span><span lang=EN-US>.
fork()</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>호출한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>부모</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>새롭게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만들어진</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스라</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span
lang=EN-US>. fork()</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>호출되면</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>커널은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>부모</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>데이터</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스택</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>힙을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>복사하여</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만든다</span><span
lang=EN-US>. fork()</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>성공적으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만들게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되면</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>부모</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에겐</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span
lang=KO> </span><span lang=EN-US>ID</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>값을</span><span lang=EN-US>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>자식</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에겐</span><span lang=KO> </span><span
lang=EN-US>0</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반환한다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만드는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>데에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실패하면</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>부모</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에게</span><span
lang=KO> </span><span lang=EN-US>-1</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>반환한다</span><span lang=EN-US>. fork()</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>호출하고</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>별다른</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다면</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>만드는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>데에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>성공하여도</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>부모</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span><span lang=KO> </span><span
lang=EN-US>fork() </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>호출</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이후와</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>같은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>코드가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행된</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>뒤</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>종료되기</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때문에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>완전히</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>새로운</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하려면</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에서</span><span
lang=KO> </span><span lang=EN-US>execve() </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>시스템</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>호출을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하도록</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>코드를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>작성해야</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc115530926"><b><span
lang=EN-US>execve()</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US>execve() </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>호출은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>완전히</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>새로운</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행하도록</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>호출이다</span><span lang=EN-US>. execve()</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span lang=KO> </span><span
lang=EN-US>3</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>매개변수를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지는데</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>첫번째로는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>완전한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>경로를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>포함한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일명</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>두번째로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행할</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>넘길</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>전달인자</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>마지막으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>환경변수</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>값이다</span><span
lang=EN-US>. execve()</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>성공적으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>새로운</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행했을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때에는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>아무것도</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반환하지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>않지만</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실패했다면</span><span
lang=KO> </span><span lang=EN-US>-1</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>반환한다</span><span lang=EN-US>. C </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>라이브러리에서는</span><span lang=KO> </span><span
lang=EN-US>execvp(), execlp() </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>등</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>새로운</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>여러가지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>함수들을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>제공하는데</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>함수들</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span><span
lang=KO> </span><span lang=EN-US>execve()</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>를</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>통해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>구현되어</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>함수명</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>끝에</span><span lang=KO> </span><span
lang=EN-US>v</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>나</span><span
lang=KO> </span><span lang=EN-US>l</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>전달인자와</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>관련이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는데</span><span
lang=EN-US>, v</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>전달인자</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>매개변수를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>벡터</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>즉</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>배열로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>받는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것이고</span><span
lang=EN-US>, l</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>전달인자들을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하나씩</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>따로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>매개변수로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>받는다는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>뜻이다</span><span
lang=EN-US>. e</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>나</span><span
lang=KO> </span><span lang=EN-US>p</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>환경변수와</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>관련된</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것으로</span><span
lang=EN-US>, e</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>환경변수를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>따로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>매개변수로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>지정해줄</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>뜻이고</span><span
lang=EN-US>, p</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>환경변수</span><span
lang=KO> </span><span lang=EN-US>PATH</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>등록된</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>경로들을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>참고하여</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>파일을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행한다는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>뜻이다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>단</span><span lang=EN-US>, e</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>환경변수를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>지정해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>준다고</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>해서</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>파일명에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>완전한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>경로를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>포함하지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>않아도</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>뜻은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>아니다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>단지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>매개변수로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>받은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>환경변수를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>파일에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>넘겨준다는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>뜻으로</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>파일명에는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>여전히</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>완전한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>경로를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>포함시켜줘야</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc115530927"><b><span
lang=EN-US>wait()</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US>wait(&amp;status)
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>호출은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span
lang=KO> </span><span lang=EN-US>exit()</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>통해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>아직</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>종료하지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>않았을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>중</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하나가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>종료할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>까지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>현재</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>중지시키며</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자식의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>종료</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>상태는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>인자인</span><span lang=KO> </span><span
lang=EN-US>status</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>통해</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반환하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>호출이다</span><span
lang=EN-US>.<a href="#_edn1" name="_ednref1" title=""><span
class=MsoEndnoteReference><span class=MsoEndnoteReference><span lang=EN-US
style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[i]</span></span></span></a></span><span
lang=EN-US style='font-size:7.0pt'>(</span><span lang=KO style='font-size:7.0pt;
font-family:"맑은 고딕",sans-serif'>마이클</span><span lang=KO style='font-size:7.0pt'>
</span><span lang=KO style='font-size:7.0pt;font-family:"맑은 고딕",sans-serif'>커리스크</span><span
lang=EN-US style='font-size:7.0pt'> 686) </span><span lang=EN-US>wait() </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>호출은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>여러</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>생성했을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>특정</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기다리는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>것이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>불가능하다는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>점과</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시그널에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>의해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>멈춰</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있거나</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>다시</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>재개된다는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>등의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>정보를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>알</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>없다는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>점</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>등의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>많은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>제약을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>갖고</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있는데</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>보완하기</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>위해</span><span lang=KO> </span><span
lang=EN-US>waitpid() </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>호출이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>설계됐다</span><span
lang=EN-US>. waitpid()</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=EN-US>3</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>매개변수를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>갖는데</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>첫번째로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>기다리고자</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자식</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span><span
lang=KO> </span><span lang=EN-US>pid, </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>두번째로</span><span lang=KO> </span><span lang=EN-US>wait(&amp;status)</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>동일한</span><span lang=KO> </span><span
lang=EN-US>status, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>마지막으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>어떤</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>추가적으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>정보를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반환할지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>정하는</span><span
lang=KO> </span><span lang=EN-US>options</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>이다</span><span lang=EN-US>.<a href="#_edn2" name="_ednref2"
title=""><span class=MsoEndnoteReference><span class=MsoEndnoteReference><span
lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[ii]</span></span></span></a></span><span
lang=EN-US style='font-size:7.0pt'>(</span><span lang=KO style='font-size:7.0pt;
font-family:"맑은 고딕",sans-serif'>마이클</span><span lang=KO style='font-size:7.0pt'>
</span><span lang=KO style='font-size:7.0pt;font-family:"맑은 고딕",sans-serif'>커리스크</span><span
lang=KO style='font-size:7.0pt'> </span><span lang=EN-US style='font-size:7.0pt'>722-723)</span></p>

<p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
word-break:keep-all'><span lang=EN-US style='font-size:24.0pt'>&nbsp;</span></p>

<h2><a name="_Toc115530929"><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>구현</span></b></a><b><span lang=KO
style='font-size:14.0pt'> </span></b><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>환경</span></b></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>운영체제</span><span
lang=EN-US> : macOS</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>언어</span><span
lang=KO> </span><span lang=EN-US>: C++17</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일러</span><span
lang=KO> </span><span lang=EN-US>: clang 14.0.0</span></p>

<p class=MsoNormal><span lang=EN-US>Makefile </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>사용하여</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가능</span><span lang=KO> </span><span
lang=EN-US>(macOS, Linux)</span></p>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

</div>

</body>

</html>
