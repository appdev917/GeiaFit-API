                    
                  <div class="row text-center plans">
                  	<?php //dsm($pricing_plan); ?>
            		<?php print render($pricing_plan); ?>
                    
                </div><!-- End row plans-->
                    <?php dsm($programs_price); ?>

                    <div class=" table-responsive">
						<table class="table table-striped">
						<thead>
						<tr>
							<th>&nbsp;</th>
							<th>Bronze Plan</th>
							<th>Silver Plan</th>
							<th>Gold Plan</th>
						  </tr>
						</thead>
						<tbody>
						<?php foreach ($programs_price['nodes'] as $key => $node):?>
							<?php if(is_array($node)): ?>
								<?php dsm($node);?>
								<tr>
									<td><strong>Cardio</strong></td>
									<td>$89</td>
									<td>$189</td>
									<td>$289</td>
								</tr>
							<?php endif; ?>
						<?php endforeach; ?>
						
						</tbody>
						</table>
					</div>
                    