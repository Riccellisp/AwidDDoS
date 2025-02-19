function report = detectionModule(timeByDestination,sourceByDestination,...
    responseByDestination,windowLength,threshold,normalTraffic)
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
% %Se o tamanho da janela for igual a 1, trata-se de um tráfego normal
if (length(timeByDestination) == 1)
    numeroAtaques = 0;
    numeroNormal = 1;
    falsePositive = 0;
    falseNegative = 0;
    accuracy = 1;
    packetRate(1) = 1;
    varSourceIPs(1) = 0;
    entropySourceIPs(1) = 0;
    
    report = {numeroAtaques, numeroNormal,falsePositive,falseNegative,...
        accuracy,packetRate, varSourceIPs, entropySourceIPs,responseByDestination};
else
    
    while(nextPkt < length(timeByDestination))
        %       Splitting in seconds
        for i = nextPkt:length(timeByDestination)
            if(~isWindow(timeByDestination(nextPkt),timeByDestination(i),windowLength))
                n = n + 1;
            else
                break;
            end
        end
        %       Geting true responses
%         keyboard
        if (~isempty(find(strcmp(responseByDestination(nextPkt:n),'normal') ~= 1 )))
            disp('tem ataque real');
            flagAttack = 1;
            realWindowResponse(janelas + 1) = 1;
%             keyboard
        else
            flagNormal = 1;
            realWindowResponse(janelas + 1) = 0;

        end
        
        %         Getting Features
        
        entropySourceIPs(janelas + 1)= entropy2([sourceByDestination(nextPkt:n)]);
        varSourceIPs(janelas + 1) = length(unique([sourceByDestination(nextPkt:n)]))/length(sourceByDestination);
        packetRate(janelas + 1) = n;

        %         Detection Module
        NaHidModule(janelas+1) = NaHid([packetRate(janelas + 1)...
            varSourceIPs(janelas + 1) entropySourceIPs(janelas + 1)],normalTraffic);
        

        
        if(NaHidModule(janelas + 1) <  threshold)
            %                 disp('traffic');
            %                 disp(janelas);
            %                 disp('atack');
            numeroAtaques = numeroAtaques + 1;
            
            %                 Getting false negatives and errors
            
            if(flagNormal)
                falsePositive= falsePositive + 1;
                errors = errors + 1;
            end
            %             plotResultsAwid(NaHidModule,threshold,entropySourceIPs,varSourceIPs,packetRate);
            
            
        else
            %                 disp('traffic');
            %                 disp(janelas);
            %                 disp('normal');
            
            normalTraffic = [packetRate(janelas + 1) varSourceIPs(janelas + 1) entropySourceIPs(janelas + 1)];
            numeroNormal = numeroNormal+ 1;
            
            if(flagAttack)
                %                 Getting false negatives and errors
                falseNegative = falseNegative + 1;
                errors = errors + 1;
            end
        end
        janelas = janelas + 1;
        nextPkt = n + 1;
    end
    
    %       Getting detection rate
    accuracy = (1 - (errors/janelas));
    report = {numeroAtaques, numeroNormal,falsePositive,falseNegative,...
        accuracy,packetRate, varSourceIPs, entropySourceIPs,realWindowResponse};
    
end
end