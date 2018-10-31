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
            if (~isempty(find(strcmp(responseByDestination(nextPkt:n),'normal') ~= 1 )))
                disp('tem ataque real');
                flagAttack = 1;
            else
                flagNormal = 1;
            end
            
            %         Getting Features
            
            entropySourceIPs= entropy2([sourceByDestination(nextPkt:n)]);
            varSourceIPs = length(unique([sourceByDestination(nextPkt:n)]))/length(sourceByDestination);
            packetRate = n;
            %         Detection Module
            NaHidModule(janelas+1) = NaHid([packetRate varSourceIPs entropySourceIPs],normalTraffic);

            janelas = janelas + 1;
            nextPkt = n + 1;
            
            if(NaHidModule <  threshold)
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
                
                normalTraffic = [packetRate varSourceIPs entropySourceIPs];
                numeroNormal = numeroNormal+ 1;
                
                if(flagAttack)
                    %                 Getting false negatives and errors
                    falseNegative = falseNegative + 1;
                    errors = errors + 1;
                end                
            end
        end
            
            %       Getting detection rate
            accuracy = (1 - (errors/janelas));
            
            report = {numeroAtaques, numeroNormal,falsePositive,falseNegative,...
                accuracy};
%             keyboard
        

end