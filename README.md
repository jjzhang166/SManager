<h1>SManager 项目主页</h1>
项目目的是要创建一套完整的个人信息管理系统

项目包含的子项目：<br />
Payment                                         个人支出管理系统<br />
KeyManager                                      个人帐号密码管理<br />
Update                                             SManger项目软件自动更新<br />
&nbsp;<br />
项目托管：<br />
website: http://gkc.asia/smanager-index
Payment : <a href="http://git.oschina.net/jakes/smanager">http://git.oschina.net/jakes/SManager</a>    Git@OSC <br />

目前就这么些，本项目的目的主要是训练技能。最后将创建一个框架，用于集成以上子项目，不过插件的知识现在正在学习，一切都尽在摸索中。

&nbsp;
<h2>项目进度</h2>
<h3>Payment</h3>
<h4 style="padding-left: 30px;">Development: Version 1.2</h4>
<p style="padding-left: 30px;">1. 添加远程MYSQL存储功能（需要自行申请可用于远程管理的MYSQL数据库)</p>
<p style="padding-left: 30px;">2. 添加自动升级功能</p>
<p style="padding-left: 30px;"></p>

<h4 style="padding-left: 30px;">Release : Version 1.1</h4>
<p style="padding-left: 30px;">1. 修复当本地数据库文件data.db不存在时，程序无法自行创建的BUG。</p>
<p style="padding-left: 30px;">2. 添加删除功能</p>

<h4 style="padding-left: 30px;">Release : Version 1.o</h4>
<p style="padding-left: 30px;">1. 实现窗口化，并美化窗口</p>
<p style="padding-left: 30px;">2. 实现QSqlite类，管理sqlite的操作</p>
<p style="padding-left: 30px;">3. 完善ListCtrl部件</p>
&nbsp;
<h3>KeyManager (筹划中)</h3>
<p style="padding-left: 30px;">筹划中...</p>

<h3>Update</h3>
<h4 style="padding-left: 30px;">Development : version 0.1</h4>
<p style="padding-left: 30px;">1. 实现从配置文件中读取本地软件中的信息</p>
<p style="padding-left: 30px;">2. 实现从配置文件中获取服务器相关信息，尝试从服务器获取版本信息，进行比对，提示</p>
<p style="padding-left: 30px;">3. 从服务器下载升级需要的文件</p>
<p style="padding-left: 30px;">4. 检测主程序是否在运行，并提示相关信息</p>
<p style="padding-left: 30px;">5. 安全覆盖程序，完成升级</p>
<p style="padding-left: 30px;"></p>