% % parameters
windowLength = 1;
threshold = 0.8;

cd testesplit
files = dir('new*');

for file=1:length(files)
    
    dataset = textread(files(file).name, '%s', 'delimiter', ',','whitespace', '');
    cd ..
    interval = 0:((length(dataset)/155)-1);
    sourceIPs = dataset(76 +155*[interval]);
    time = str2double(dataset(4 +155*[interval]));
    response = dataset(155 +155*[interval]);
    normalTraffic = [539, 0.005000000000000, 1.319659453970128   ];
    firstPacketWindowTime = time(1) + 1;
    n = 0;
    nextPkt = 1;
    janelas = 0;
    numeroAtaques = 0;
    numeroNormal = 0;
    flagAttack = 0;
    flagNormal = 0;
    falsePositive = 0;
    falseNegative = 0;
    errors = 0;
    while(nextPkt < length(interval))
        
        for i = nextPkt:length(interval)
            %         if(nextPkt == 962)
            %         keyboard;
            %         end
            if(~isWindow(time(nextPkt),time(i),windowLength))
                n = n + 1;
            else
                break;
            end
        end
        if (~isempty(find(strcmp(response(nextPkt:n),'normal') ~= 1 )))
            disp('tem ataque real');
            flagAttack = 1;
        else
            flagNormal = 1;
        end
        entropySourceIPs= entropy2([sourceIPs(nextPkt:n)]);
        varSourceIPs = length(unique([sourceIPs(nextPkt:n)]))/length(sourceIPs);
        packetRate = n;
        NaHidModule = NaHid([packetRate varSourceIPs entropySourceIPs],normalTraffic);
        janelas = janelas + 1;
        nextPkt = n + 1;
        
        if(NaHidModule <  threshold)
            disp('traffic');
            disp(janelas);
            disp('atack');
            numeroAtaques = numeroAtaques + 1;
            
            
            if(flagNormal)
                falsePositive= falsePositive + 1;
                errors = errors + 1;
            end
            
        else
            disp('traffic');
            disp(janelas);
            disp('normal');
            
            normalTraffic = [packetRate varSourceIPs entropySourceIPs];
            numeroNormal = numeroNormal+ 1;
            
            if(flagAttack)
                falseNegative = falseNegative + 1;
                errors = errors + 1;
            end
            
        end
        
        accuracy = (1 - errors/janelas);
        
    end
    cd testesplit
end