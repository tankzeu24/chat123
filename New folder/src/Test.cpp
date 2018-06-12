
/*

//UNION
 ContextFreeGrammar cfg1, cfg2, result;

           cfg1 << "I{A1}";
			cfg1 << "{A1}->ab{B}";

			cfg2 << "I{A2}";
			cfg2 << "{A2}->{G}";

			result.createAsUnionOf(cfg1, cfg2);
			result.printRules();
//CONCAT

ContextFreeGrammar cfg1, cfg2, result;

			cfg1 <<"I{S1}"
                 <<"{S1}->a";

			cfg2  << "I{S2}"
			      << "{S2}->b";

			result.createAsConcatenationOf(cfg1, cfg2);
			result.printRules();


    //ITERATION

    ContextFreeGrammar cfg, result;

			cfg << "I{VAR}";
			cfg << "{VAR}->{A}{B}";

			result.createAsIterationOf(cfg);

			IsTrue(result.getRules().size() == 4);
			IsTrue(result.getInitialVariable() != Variable("VAR"));


 ContextFreeGrammar cfg;

			RightSide rs;

			cfg.setInitialVariable(Variable("VAR"));

			rs.append(Terminal('a'));
			rs.append(Variable("VAR"));

			// add the rule {VAR} -> a{VAR}
			cfg.addRule(Rule(Variable("VAR"), rs));

			// add the rule {VAR} -> @
			cfg.addRule(Rule(Variable("VAR")));
			// this grammar generates words that contain only 'a'
			cout<< cfg.wordBelongsToLanguage("aaaa").usingPushdownAutomaton();
			cout<<cfg.wordBelongsToLanguage("ab").usingPushdownAutomaton();


     ContextFreeGrammar cfg, result;
            cfg << "I{VAR}";
			cfg << "{VAR}->{A}{B}";

			result.createAsIterationOf(cfg);
			result.printRules();
			//result.getRules().size() == 4;



// TEST FOR CHOMSKY YES/NO

       ContextFreeGrammar cfg;

			RightSide rs1;
			rs1.append(Terminal('f'));

			// rule V -> f
			Rule rule1(Variable("V"), rs1);

			RightSide rs2;
			rs2.append(Variable("A"));
			rs2.append(Variable("B"));

			Rule rule2(Variable("V"), rs2);
			cfg.addRule(rule2);

			cout<<cfg.isChomskyNormal();
			// it is true;

           //NO
          ContextFreeGrammar cfg;
               cfg<<"I{S}"
                  <<"{S}->{A}b"
                  <<"{S}->{B}";
               cout<<cfg.isChomskyNormal();

//CONVER TO CHOMSKY Chomskify
ContextFreeGrammar cfg;

			RightSide rs1;
			rs1.append(Terminal('f'));
			rs1.append(Variable("VAR"));

			// rule V -> f{VAR}
			Rule rule1(Variable("V"), rs1);
			Rule rule2(Variable("VAR"), rs1);
			Rule rule3(Variable("VAR"));

			cfg.addRule(rule1);
			cfg.addRule(rule2);
			cfg.addRule(rule3);
			//	rule2();
			cout<<(cfg.isChomskyNormal());

			cfg.convertToChomskyNormal();

			cout<<(cfg.isChomskyNormal());

//LANGUAGE EMPTY OR NOT


   //NO
         ContextFreeGrammar cfg;

			cfg << "I{S}"
				<< "{S}->{A}{B}"
				<< "{A}->b"
				<< "{B}->a";
				cout<<cfg.languageIsEmpty();
     //YES
      ContextFreeGrammar cfg;

			cfg << "I{S}"
				<< "{S}->{A}{B}"
				<< "{A}->b";
				cout<<cfg.languageIsEmpty();

//ADD RULE

 ContextFreeGrammar cfg;
			RightSide rs;
			Rule r("A", rs);

			cfg.addRule(r);

			rs.append(Terminal('f'));
			Rule w("A", rs);

			cfg.addRule(w);
			cfg.printRules();
//REMOVE RULE
   ContextFreeGrammar cfg;

			RightSide rs1;
			rs1.append(Terminal('f'));

			// rule V -> f
			Rule rule1(Variable("V"), rs1);
             cfg.addRule(rule1);
			RightSide rs2;
			rs2.append(Variable("A"));
			rs2.append(Variable("B"));

			Rule rule2(Variable("V"), rs2);
			cfg.addRule(rule2);
             cfg.printRules();
             cout<<"Now I will delete 1 rule "<<endl;
             cfg.RemoveRule(rule2);
             cfg.printRules();

			*/










