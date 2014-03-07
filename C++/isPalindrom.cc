class Solution {
public:   
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int strLen = s.length();
        int j = 0;
        
        for (int i = 0; i < strLen; i++)
        {
            if (isalnum(s[i]))
            {
                s[j++] = tolower(s[i]);
            }
        }
        
        j--;
        
        for (int i = 0; i <= j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        
        return true;
    }    
};


input	output	expected	
""	true	true	
   
" "	true	true	
   
"."	true	true	
   
"a"	true	true	
   
"a."	true	true	
   
".a"	true	true	
   
".,"	true	true	
   
"ab"	false	false	
   
"aa"	true	true	
   
"aA"	true	true	
   
"!!!"	true	true	
   
"a a"	true	true	
   
"a ba"	true	true	
   
"a.b,."	false	false	
   
"aba"	true	true	
   
"abb"	false	false	
   
"Bab"	true	true	
   
"1a2"	false	false	
   
"1b1"	true	true	
   
"abba"	true	true	
   
"ab2a"	false	false	
   
"ab@a"	true	true	
   
"c#dc"	true	true	
   
"......a....."	true	true	
   
"A man, a plan, a canal: Panama"	true	true	
   
"race car"	true	true	
   
"race a car"	false	false	
   
"Sore was I ere I saw Eros."	true	true	
   
"A man, a plan, a canal -- Panama"	true	true	
   
"Never a foot too far, even."	true	true	
   
"Euston saw I was not Sue."	true	true	
   
"Live on evasions? No, I save no evil."	true	true	
   
"Red Roses run no risk, sir, on nurses order."	true	true	
   
"Salisbury moor, sir, is roomy. Rub Silas."	true	true	
   
"Marge, let's "went." I await news telegram."	true	true	
   
"A new order began, a more Roman age bred Rowena."	true	true	
   
"I, man, am regal; a German am I."	true	true	
   
"Tracy, no panic in a pony-cart."	true	true	
   
"Egad! Loretta has Adams as mad as a hatter. Old age!"	true	true	
   
"Eve, mad Adam, Eve!"	true	true	
   
"Resume so pacific a pose, muser."	true	true	
   
"Marge let a moody baby doom a telegram."	true	true	
   
"Tenet C is a basis, a basic tenet."	true	true	
   
"Nella's simple hymn: "I attain my help, Miss Allen.""	true	true	
   
"Straw? No, too stupid a fad. I put soot on warts."	true	true	
   
"Sir, I demand, I am a maid named Iris."	true	true	
   
"Lay a wallaby baby ball away, Al."	true	true	
   
"Tessa's in Italy, Latin is asset."	true	true	
   
"Noel sees Leon."	true	true	
   
"No, it can assess an action."	true	true	
   
"Bob: "Did Anna peep?" Anna: "Did Bob?""	true	true	
   
"Sex at noon taxes."	true	true	
   
"Egad, a base life defiles a bad age."	true	true	
   
""Stop!" nine myriad murmur. "Put up rum, rum, dairymen, in pots.""	true	true	
   
"Delia, here we nine were hailed."	true	true	
   
"Not I, no hotel, cycle to Honiton."	true	true	
   
"Anne, I vote more cars race Rome-to-Vienna."	true	true	
   
"Mother Eve's noose we soon sever, eh, Tom?"	true	true	
   
""Sue," Tom smiles, "Selim smote us.""	true	true	
   
"Telegram, Margelet!"	true	true	
   
"Too hot to hoot."	true	true	
   
"Unglad, I tar a tidal gnu."	true	true	
   
"Eve damned Eden, mad Eve."	true	true	
   
"Snug Satraps eye Sparta's guns."	true	true	
   
"Nurse, save rare vases, run!"	true	true	
   
"Draw, O Caesar, erase a coward."	true	true	
   
"No mists or frost, Simon."	true	true	
   
"Sail on, game vassal! Lacy callas save magnolias!"	true	true	
   
"Trap a rat! Stare, piper, at Star apart."	true	true	
   
"Sue, dice, do, to decide us."	true	true	
   
"La, Mr. O'Neill, lie normal."	true	true	
   
"Top step -- Sara's pet spot."	true	true	
   
"Eel-fodder, stack-cats red do flee."	true	true	
   
"Reg, no lone car won, now race no longer."	true	true	
   
"Zeus was deified, saw Suez."	true	true	
   
"Evil is a name of a foeman, as I live."	true	true	
   
"No waste, grab a bar, get saw on."	true	true	
   
""Degenerate Moslem, a cad!" Eva saved a camel so Meta reneged."	true	true	
   
"Was it felt? I had a hit left, I saw."	true	true	
   
"Won't I repaper? Repaper it now."	true	true	
   
"Too far, Edna, wander afoot."	true	true	
   
"Stella won no wallets."	true	true	
   
""Do nine men interpret?" "Nine men," I nod."	true	true	
   
"Nurse, I spy gypsies, run!"	true	true	
   
"Draw pupil's pup's lip upward."	true	true	
   
"Lewd did I live, and, Edna, evil I did dwel."	true	true	
   
""Sirrah! Deliver deified desserts detartrated!" stressed deified, reviled Harris."	true	true	
   
"All erotic, I lose my lyme solicitor, Ella."	true	true	
   
"No, is Ivy's order a red rosy vision?"	true	true	
   
"No word, no bond, row on."	true	true	
   
"On tub, Edward imitated a cadet; a timid raw debut, no?"	true	true	
   
"Tense, I snap Sharon roses, or Norah's pansies net."	true	true	
   
""Deliver desserts," demanded Nemesis, "emended, named, stressed, reviled.""	true	true	
   
"No, it is opposed; Art sees Trade's opposition."	true	true	
   
""Knight, I ask nary rank," saith gink."	true	true	
   
"Moors dine, nip -- in Enid's room."	true	true	
   
""Ma," Jerome raps pot top, "spare more jam!""	true	true	
   
"Live not on evil deed, live not on evil."	true	true	
   
"Sir, I'm Iris!"	true	true	
   
"Now do I repay a period won."	true	true	
   
"A rod, not a bar, a baton, Dora."	true	true	
   
"Now saw ye no mosses or foam, or aroma of roses. So money was won."	true	true	
   
"Amiced was I ere I saw Decima."	true	true	
   
""Pooh," smiles Eva, "have Selim's hoop.""	true	true	
   
"No, set a maple here, help a mate, son."	true	true	
   
"A war at Tarawa!"	true	true	
   
"Some men interpret nine memos."	true	true	
   
"Delia sailed as sad Elias ailed."	true	true	
   
"Ned, I am a maiden."	true	true	
   
"Dennis sinned."	true	true	
   
"Remit Rome cargo to go to Grace Mortimer."	true	true	
   
"Did Dean aid Diana? Ed did."	true	true	
   
"I told Edna how to get a mate: "Go two-handed." Loti."	true	true	
   
"Sire, was I ere I saw Eris?"	true	true	
   
"Now Eve, we're here, we've won."	true	true	
   
""Suit no regrets." A motto, Master Gerontius."	true	true	
   
"Eve, man, am Eve!"	true	true	
   
"Slap-dab set-up, Mistress Ann asserts, imputes bad pals."	true	true	
   
"Tuna nut."	true	true	
   
"Saladin enrobes a baroness, Senora, base-born Enid, alas."	true	true	
   
"Deny me not; atone, my Ned."	true	true	
   
"Roy Ames, I was a wise mayor."	true	true	
   
"Wonders in Italy, Latin is "Red" now."	true	true	
   
"'Tis Ivan on a visit."	true	true	
   
"Did Ione take Kate? No, I did."	true	true	
   
"Solo gigolos."	true	true	
   
"No, it is open on one position."	true	true	
   
"He Goddam Mad Dog, Eh?"	true	true	
   
"Ned, go gag Ogden."	true	true	
   
"Draw no dray a yard onward."	true	true	
   
""Revolt, love!" raved Eva. "Revolt, lover!""	true	true	
   
"Enid and Edna dine."	true	true	
   
"Anne, I stay a day at Sienna."	true	true	
   
"Senile felines."	true	true	
   
"Max, I stay away at six A.M."	true	true	
   
"Ere hypocrisies or poses are in, my hymn I erase. So prose I, sir, copy here."	true	true	
   
"St. Simon sees no mists."	true	true	
   
"Draw, O coward!"	true	true	
   
"Top step's pup's pet spot."	true	true	
   
"Noel, did I not rub Burton? I did, Leon."	true	true	
   
"Puss, a legacy! Rat in a snug, unsanitary cage, lass, up!"	true	true	
   
"Rise to vote, Sir."	true	true	
   
"Noel saw I was Leon."	true	true	
   
"Now, sir, a war is won!"	true	true	
   
"Ha! Robed Selim smiles, Deborah!"	true	true	
   
"Degas, are we not drawn onward, we freer few, drawn onward to new eras aged?"	true	true	
   
"Now ere we nine were held idle here, we nine were won."	true	true	
   
"Yo! Bottoms up, U.S. Motto, boy!"	true	true	
   
"Nor I nor Emma had level'd a hammer on iron."	true	true	
   
"Al lets Della call Ed, Stella."	true	true	
   
"No Dot nor Ottawa, "legal age" law at Toronto, Don."	true	true	
   
"Yes, Mark, cable to hotel, "Back Ramsey.""	true	true	
   
"Was it a bar or a bat I saw?"	true	true	
   
"Marge lets Norah see Sharon's telegram."	true	true	
   
"Analytic Paget saw an inn in a waste-gap city, Lana."	true	true	
   
"Was raw tap ale not a reviver at one lap at Warsaw?"	true	true	
   
"Live on, Time; emit no evil."	true	true	
   
""Not for Cecil?" asks Alice Crofton."	true	true	
   
"Ban campus motto, "Bottoms up, MacNab.""	true	true	
   
"So may Apollo pay Amos."	true	true	
   
"Norma is as selfless as I am, Ron."	true	true	
   
"Arden saw I was Nedra."	true	true	
   
"Won't lovers revolt now?"	true	true	
   
"Do not start at rats to nod."	true	true	
   
"Ha! On, on, o Noah!"	true	true	
   
"Norah's foes order red rose of Sharon."	true	true	
   
"I made border bard's drowsy swords; drab, red-robed am I."	true	true	
   
"Emil, asleep, Hannah peels a lime."	true	true	
   
"Set a broom on no moor, Bates."	true	true	
   
"Ten dip a rapid net."	true	true	
   
"O render gnostic illicit song, red Nero."	true	true	
   
"Are we not drawn onwards, we Jews, drawn onward to new era?"	true	true	
   
"Mother at song no star, eh Tom?"	true	true	
   
"I maim nine men in Saginaw; wan, I gas nine men in Miami."	true	true	
   
"So may get Arts award. Draw a strategy, Amos."	true	true	
   
"Nella, demand a lad named Allen."	true	true	
   
"Yes, Syd, Owen saved Eva's new Odyssey."	true	true	
   
""Now dine," said I as Enid won."	true	true	
   
"Lepers repel."	true	true	
   
"May a moody baby doom a yam?"	true	true	
   
"Draw -- aye, no melody -- dole-money award."	true	true	
   
"Mirth, sir, a gay asset? No, don't essay a garish trim."	true	true	
   
"See few owe fees."	true	true	
   
"Stressed was I ere I saw desserts."	true	true	
   
"Name I -- Major-General Clare -- negro Jamie Man."	true	true	
   
"Tennis set won now Tess in net."	true	true	
   
"Ewer of miry rim for ewe."	true	true	
   
"Sh! Tom sees moths."