# Part 1. Инструмент ipcalc

## 1.1. Сети и маски

Для работы используем утилиту ipcalc.

Определение адреса сети 192.167.38.54/13:

![](screenshots/ipcalcaddr.png)

Перевод маски 255.255.255.0 в префиксную и двоичную запись:

![](screenshots/maskbinandprefix.png)

Перевод маски /15 в обычную и двоичную запись:

![](screenshots/prefixtobin.png)

Перевод маски 11111111.11111111.11111111.11110000 в префиксную и обычную запись:

![](screenshots/binarytoprefix.png)

Минимальный и максимальный хост в сети 12.167.38.4 при различных масках: 

/8:

![](screenshots/minmaxhostmask8.png)

1111111.11111111.00000000.00000000:

![](screenshots/minmaxhostbin.png)

255.255.254.0:

![](screenshots/minmaxhost_mask23.png)

/4:

![](screenshots/minmaxhostmask4.png)

## 1.2. localhost

Используем ip a для вывода списка сетевых интерфейсов
![](screenshots/ip_a.png)

Используем ipcalc для получения информации о сети для адреса 127.0.0.1/8

![](screenshots/localhost.png)

Из перечисленных IP адресов : 194.34.23.100, 127.0.0.2, 127.1.0.1, 128.0.0.1
в диапазон HostMin/HostMax войдут: 127.0.0.2, 127.1.0.1.


## 1.3. Диапазоны и сегменты сетей

По стандарту, для частных IP-адресов существуют три диапазона:

10.0.0.0 - 10.255.255.255 (10.0.0.0/8)
172.16.0.0 - 172.31.255.255 (172.16.0.0/12)
192.168.0.0 - 192.168.255.255 (192.168.0.0/16)

Публичные IP: 134.43.0.2, 172.0.2.1, 192.172.0.1, 172.68.0.2, 192.169.168.1
Частные IP: 10.0.0.45, 192.168.4.2, 172.20.250.4, 172.16.255.255, 10.10.10.10 

Для сети 10.10.0.0/18 возможны следующие IP адреса шлюза: 10.10.0.2, 10.10.10.10, 10.10.1.255
(10.0.0.1, 10.10.100.11 - невозможны)

# Part 2. Статическая маршрутизация между двумя машинами

Поднял вторую виртуальную машину.
Установил в настройках виртуальных машин Network - Internal network

Вызвал команду ip -a для просмотра сетевых интерфейсов 

![](screenshots/ip_a_clone.png)

Меняю настройки etc/netplan/00-installer-config.yaml для каждой машины.
Необходимо задать следующие адреса и маски: ws1 - 192.168.100.10, маска /16, ws2 - 172.24.116.8, маска /12

![](screenshots/yaml1.png)

![](screenshots/netplanapply1.png)

![](screenshots/yaml2.png)

![](screenshots/netplanapply2.png)

## 2.1. Добавить статический маршрут вручную

Задаю статический маршрут от одной машины к другой через команды:

для ws1: sudo ip r add 172.24.116.8 dev enp0s3
для ws2: sudo ip r add 192.168.100.10 dev enp0s3

результат выполнения команд можно увидеть в выводе команды ip route и вызвав команду:
для ws1: ping 172.24.116.8

![](screenshots/ping1.png)

для ws2: ping 192.168.100.10

![](screenshots/ping2.png)

## 2.2. Добавить статический маршрут с сохранением

Добавить статический маршрут от одной машины до другой с помощью файла etc/netplan/00-installer-config.yaml

![](screenshots/staticroutews.png)

для ws1: ping 172.24.116.8
для ws2: ping 192.168.100.10

![](screenshots/pingws.png)

# Part 3. Утилита iperf3

## 3.1. Скорость соединения

8 Mbps = 1 MB/s
100 MB/s = 819200 Kbps
1 Gbps = 1024 Mbps

## 3.2. Утилита iperf3

Для измерения скорости соединения между ws1 и ws2 необходимо установить утилиту iperf3

На ws2 запускаем iperf3 в режиме сервера командой iperf3 -s
На ws1 вызываем iperf3 -c 172.24.116.8

![](screenshots/iperf3.png) 

# Part 4. Сетевой экран

## 4.1. Утилита iptables

Создать файл /etc/firewall.sh, имитирующий фаерволл, на ws1 и ws2.

Нужно добавить в файл подряд следующие правила:

1) На ws1 применить стратегию, когда в начале пишется запрещающее правило, а в конце пишется разрешающее правило (это касается пунктов 4 и 5)

2) На ws2 применить стратегию, когда в начале пишется разрешающее правило, а в конце пишется запрещающее правило (это касается пунктов 4 и 5)

3) Открыть на машинах доступ для порта 22 (ssh) и порта 80 (http)

4) Запретить echo reply (машина не должна «пинговаться», т.е. должна быть блокировка на OUTPUT)

5) Разрешить echo reply (машина должна «пинговаться»)

![](screenshots/firewall.png)

Протокол Internet Control Message Protocol (ICMP) – это набор коммуникационных правил, которые устройства используют для распространения информации об ошибках передачи данных в сети. 

Запустить файлы на обеих машинах командами chmod +x /etc/firewall.sh и /etc/firewall.sh

![](screenshots/firewall_applying.png)

Allow by default (Разрешить по умолчанию): При использовании этой стратегии все трафики разрешаются по умолчанию, если для них не установлены явные правила блокировки. То есть все, что не запрещено, автоматически разрешено. Это может упростить управление брандмауэром, но может также привести к потенциальным уязвимостям, если нежелательные соединения не будут правильно заблокированы.

Deny by default (Запретить по умолчанию): При использовании этой стратегии все трафики блокируются по умолчанию, если для них не установлены явные правила разрешения. Это более безопасный подход, так как все, что не разрешено, будет автоматически заблокировано. Однако требует более тщательной настройки для разрешения необходимого трафика и может потребовать больше времени и усилий для управления. Если сначала стоит запрещающее правило, то оно имеет приоритет перед последующим разрешающим.

Выбор между этими стратегиями зависит от конкретных требований безопасности и сетевых сценариев. В некоторых случаях удобнее использовать "allow by default", чтобы упростить настройку и обслуживание системы. Однако в более критических средах чаще предпочитают "deny by default" для повышения безопасности и более строгого контроля над трафиком.

## 4.2. Утилита nmap

Командой ping находим машину, которая не «пингуется», это ws1. После чего утилитой nmap показываю, что хост машины запущен (в выводе nmap должно быть сказано: Host is up).

![](screenshots/nmap.png)

# Part 5. Статическая маршрутизация сети

Поднять пять виртуальных машин (3 рабочие станции (ws11, ws21, ws22) и 2 роутера (r1, r2))

## 5.1. Настройка адресов машин

Настроить конфигурации машин в etc/netplan/00-installer-config.yaml согласно сети на рисунке:

![](screenshots/part5_network.png)

Конфигурация ws11:

![](screenshots/ws11conf.png)

r1 и r2:

![](screenshots/r1r2conf.png)

ws21 и ws22:

![](screenshots/ws21ws22conf.png)

Перезапустить сервис сети. Если ошибок нет, то командой ip -4 a проверить, что адрес машины задан верно.

Вывод команды для ws11:

![](screenshots/ip4aws11.png)

r1 и r2:

![](screenshots/ip4ar1r2.png)

ws21 и ws22:

![](screenshots/ip4aws21ws22.png)

Пропинговать ws22 с ws21:

![](screenshots/ws21ws22ping.png)


Пропинговать r1 с ws11:

![](screenshots/ws11r1ping.png)


## 5.2. Включение переадресации IP-адресов

Для включения переадресации IP, выполнить команду на роутерах:
sysctl -w net.ipv4.ip_forward=1

![](screenshots/forward_tmp_r1r2.png)

Открыть файл /etc/sysctl.conf и добавить в него следующую строку:

net.ipv4.ip_forward = 1

При использовании этого подхода, IP-переадресация включена на постоянной основе.

![](screenshots/forward_const.png)

## 5.3. Установка маршрута по-умолчанию

Настроить маршрут по-умолчанию (шлюз) для рабочих станций. Добавить `default` перед IP роутера в файле конфигураций для каждой рабочей машины

![](screenshots/route_default.png)

![](screenshots/ip_route_ws11_ws21_ws22.png)


Пропинговать с ws11 роутер r2 и покажи на r2, что пинг доходит.с использованием команды:

`tcpdump -tn -i eth0`

tcpdump (от TCP и англ. dump — свалка, сбрасывать) — утилита UNIX, позволяющая перехватывать и анализировать сетевой трафик, проходящий через компьютер, на котором запущена данная программа. 

-tn - не отображает метку времени в каждой строке и отображает IP-адрес вместо имени хоста. 
-i  - указывает на то, какой сетевой интерфейс будет использоваться для захвата пакетов.

![](screenshots/ws11pingr2.png)

## 5.4. Добавление статических маршрутов

Добавь в роутеры r1 и r2 статические маршруты в файле конфигураций. Пример для r1 маршрута в сетку 10.20.0.0/26:

### Добавить в конец описания сетевого интерфейса eth1:

- to: 10.20.0.0
  via: 10.100.0.12

###  

![](screenshots/r1r2r5_4.png)

![](screenshots/ip_r_5.4.png)

Запустить команды на ws11:

`ip r list 10.10.0.0/[маска сети]` и `ip r list 0.0.0.0/0`

Адрес 0.0.0.0/0 в контексте сетевых настроек обозначает "любой адрес" или "весь IP-диапазон". Он используется для указания шлюза по умолчанию, что означает, что пакеты, для которых не определен более конкретный маршрут, будут направляться через этот шлюз.

![](screenshots/ip_list.png)

## 5.5. Построение списка маршрутизаторов

Запустить на r1 команду дампа:
`tcpdump -tnv -i eth0`

Программа tcpdump собирает пакеты до тех пор, пока процесс не будет прерван сигналом.

-t - не печатает время для каждой dump line, -n - не преобразует адреса (i.e., host addresses, port numbers, etc.)
-v - предоставляет более подробный вывод, -i - слушает интерфейс.


При помощи утилиты **traceroute** построить список маршрутизаторов на пути от ws11 до ws21

![](screenshots/ws11traceroutews21.png)

Утилита Traceroute вместо ICMP-запроса отправляет 3 UDP-пакета на определенный порт целевого хоста и ожидает ответа о недоступности этого порта. Первый пакет отправляется с TTL=1, второй с TTL=2 и так далее, пока запрос не попадёт адресату (TTL - time to live - время жизни пакета). Каждый хост его -=TTL Так как вместо ICMP-запроса он отправляет UDP-запрос, в каждом запросе есть порт отправителя и порт получателя. Когда запрос попадёт на хост назначения, этот хост отправит ответ о недоступности порта «Destination port unreachable» (порт назначения недоступен). Это значит, что адресат получил запрос. Traceroute воспримет этот ответ как завершение трассировки и выведет на экран всю информацию.


## 5.6. Использование протокола **ICMP** при маршрутизации

Протокол Internet Control Message Protocol (ICMP) – это набор коммуникационных правил, которые устройства используют для распространения информации об ошибках передачи данных в сети. При обмене сообщениями между отправителем и получателем могут возникнуть непредвиденные ошибки. Например, сообщения могут быть слишком длинными или пакеты данных могут приходить не по порядку, поэтому получатель не может их организовать. В таких случаях получатель использует ICMP для информирования отправителя сообщением об ошибке и просит отправить сообщение повторно.

Запустить на r1 перехват сетевого трафика, проходящего через enp0s3:

Пропинговать с ws11 несуществующий IP (например, *10.30.0.111*) с помощью команды:

`ping -c 1 10.30.0.111`

![](screenshots/ws11pingsr1tcpdump.png)

# Part 6. Динамическая настройка IP с помощью **DHCP**

Для r2 настроить в файле */etc/dhcp/dhcpd.conf* конфигурацию службы **DHCP**:

Указать адрес маршрутизатора по-умолчанию, DNS-сервер и адрес внутренней сети. Пример файла для r2:

subnet 10.100.0.0 netmask 255.255.0.0 {}

subnet 10.20.0.0 netmask 255.255.255.192
{
    range 10.20.0.2 10.20.0.50;
    option routers 10.20.0.1;
    option domain-name-servers 10.20.0.1;
}

![](screenshots/dhcpdconf.png)

В файле resolv.conf прописать nameserver 8.8.8.8.

![](screenshots/resolv_conf.png)

Перезагрузить службу **DHCP** командой `systemctl restart isc-dhcp-server`

![](screenshots/dhcp_restart.png)

Перезагрузить службу **DHCP** командой `systemctl restart isc-dhcp-server`
Машину ws21 перезагрузить при помощи `reboot`
Посмотреть статус isc-dhcp-server командой `systemctl status isc-dhcp-server`

![](screenshots/dhcp_server_status.png)

Вывод команды ip a для ws21:

![](screenshots/ws21dhcp.png)

Пропинговать ws22 c ws21:

![](screenshots/pingws21ws22.png)

Добавить строки: `macaddress: 10:10:10:10:10:BA`, `dhcp4: true` в настройки netplan ws11:

![](screenshots/ws11macpng.png)

Для r1 настроить аналогично r2, но сделать выдачу адресов с жесткой привязкой к MAC-адресу (ws11):

![](screenshots/dhcpd_conf_r1.png)

Вызываем reboot на ws11 и смотрим вывод ip a

![](screenshots/ws11_ip_dhcp.png)

Пропинговать r1 с ws11:

![](screenshots/ws11pingsr1_dhcp.png)


Запросить с ws21 обновление ip адреса:

До:

![](screenshots/ws21_before_dhcp.png)

После:

![](screenshots/ws21_after_dhcp.png)

Для обновления ip адреса используется команда dhclient -v. DHCP-клиент (dhclient) отправляет запрос на DHCP-сервер для обновления своих сетевых настроек, включая IP-адрес. Режим -v означает "verbose" и выводит более подробную информацию о процессе.

# Part 7. **NAT**

Apache — это свободное программное обеспечение, с помощью которого можно создать веб-сервер.

В файле */etc/apache2/ports.conf* на ws22 и r1 изменить строку `Listen 80` на `Listen 0.0.0.0:80`, то есть сделать сервер Apache2 общедоступным:

![](screenshots/apache2_confws22r1.png)

Запустить веб-сервер Apache командой `service apache2 start` на ws22 и r1:

![](screenshots/apache2_start_ws22_r1.png)

Добавить в фаервол, созданный по аналогии с фаерволом из Части 4, на r2 следующие правила:

1) Удаление правил в таблице filter - `iptables -F`
2) Удаление правил в таблице "NAT" - `iptables -F -t nat`
3) Отбрасывать все маршрутизируемые пакеты - `iptables --policy FORWARD DROP`

![](screenshots/r2firewall.png)

![](screenshots/firewall_apply_r2.png)

Проверить соединение между ws22 и r1 командой `ping`
*При запуске файла с этими правилами, ws22 не должна «пинговаться» с r1*

![](screenshots/r1can'tpingws22.png)

Добавить в файл ещё одно правило:

4) Разрешить маршрутизацию всех пакетов протокола **ICMP**

![](screenshots/firewall_allow_rule.png)

Проверить соединение между ws22 и r1 командой `ping`
*При запуске файла с этими правилами, ws22 должна «пинговаться» с r1*

![](screenshots/r1pingsws22.png)

Добавить в файл ещё два правила:

5) Включить **SNAT**, а именно маскирование всех локальных ip из локальной сети, находящейся за r2 (по обозначениям из Части 5 - сеть 10.20.0.0)

6) Включить **DNAT** на 8080 порт машины r2 и добавить к веб-серверу Apache, запущенному на ws22, доступ извне сети

![](screenshots/SNAT.png)

Запустить файл.

Проверить соединение по TCP для **SNAT**: для этого с ws22 подключиться к серверу Apache на r1 командой:
`telnet [адрес] [порт]`

![](screenshots/telnetchecksSNAT.png)

Проверить соединение по TCP для **DNAT**: для этого с r1 подключиться к серверу Apache на ws22 командой `telnet` (обращаться по адресу r2 и порту 8080)

![](screenshots/telnetchecksDNAT.png)


# Part 8. Дополнительно. Знакомство с **SSH Tunnels**

SSH (Secure SHell - защищенная оболочка) — сетевой протокол прикладного уровня, предназначеный для безопасного удаленного доступа к UNIX-системам.

Запустить на r2 фаервол с правилами из Части 7.
Запустить веб-сервер **Apache** на ws22 только на localhost (то есть в файле */etc/apache2/ports.conf* измени строку `Listen 80` на `Listen localhost:80`)

![](screenshots/localhost_apache2ws22.png)

Listen localhost:80:

Эта инструкция указывает веб-серверу слушать только запросы, поступающие на локальный (127.0.0.1) интерфейс на порту 80.
Сервер будет принимать запросы только от локальной машины (localhost).

![](screenshots/apache2_is_running.png)

Воспользоваться *Local TCP forwarding* с ws21 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws21:

![](screenshots/ssh_ws21_ws22.png)

![](screenshots/closed_ssh_connection.png)

Команда ssh -L используется для создания локального порт-форвардинга (local port forwarding) с использованием SSH. 
Эта команда создает SSH туннель, который пересылает весь трафик, поступающий на локальный порт 9999, на удаленный сервер (10.20.0.20) на порт 80.

Воспользоваться *Remote TCP forwarding* c ws11 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws11:

![](screenshots/ssh_ws_11_ws_22.png)

![](screenshots/log_outws11fromws22.png)

Команда ssh -R используется для настройки удаленного порт-форвардинга (remote port forwarding) с использованием SSH.
Эта команда создает SSH туннель, который перенаправляет весь трафик, поступающий на удаленный порт 9999, на ваш локальный компьютер на порт 80.

Для проверки, сработало ли подключение в обоих предыдущих пунктах выполнить команду:
`telnet 127.0.0.1 [локальный порт]`

![](screenshots/telnet_localhostws21.png)

![](screenshots/telnetws11ws22.png)








































